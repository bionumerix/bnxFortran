#' Univariate Akima Interpolation
#'
#' The function returns a list of points which smoothly interpolate given data
#' points. For details see \code{\link[akima]{aspline}}.
#'
#' @name aspline-interface
#' @inheritParams argCallby
#' @inheritParams akima::aspline
#' @param x A vector giving the coordinates of the points to be interpolated.
#'   Alternatively a single plotting structure can be specified: see
#'   \code{\link[grDevices]{xy.coords}}.
#' @param y Same as for argument \code{x}.
#' @author Credit: This function is based on the \code{\link[akima]{aspline}}
#'   functions from \strong{package::akima} by Albrecht Gebhardt \emph{et al.}.
#'   Some minor modifications have been made to evaluate the results from the
#'   callable interface routines implemented within this packages.
#' @seealso \code{\link[akima]{aspline}}
#' @examples
#' ## regular spaced data
#'  x <- 1:10
#'  y <- c(rnorm(5), c(1,1,1,1,3))
#'  xnew <- seq(-1, 11, 0.1)
#'
#'  orig <- akima::aspline(x, y, xnew)
#'  cfun <- .aspline(x, y, xnew)
#'  ffun <- .aspline(x, y, xnew, callby = "F")
#'  stopifnot(identical(orig, cfun))
#'  stopifnot(identical(orig, ffun))
#' @export
.aspline <- function(x,
                     y = NULL,
                     xout,
                     n = 50,
                     ties = mean,
                     method = c("original", "improved"),
                     degree = 3,
                     callby = c("C", "Fortran")) {
    callby <- match.arg(callby)
    method <- match.arg(method)
    x <- xy.coords(x, y)
    y <- x$y
    x <- x$x
    nx <- length(x)
    if (any(na <- is.na(x) | is.na(y))) {
        ok <- !na
        x <- x[ok]
        y <- y[ok]
        nx <- length(x)
    }
    if (!identical(ties, "ordered")) {
        if (length(ux <- unique(x)) < nx) {
            if (missing(ties)) {
                warning("Collapsing to unique x values")
            }
            y <- as.vector(tapply(y, x, ties))
            x <- sort(ux)
            nx <- length(x)
        } else {
            o <- order(x)
            x <- x[o]
            y <- y[o]
        }
    }
    if (nx <= 1) {
        stop("need at least two non-NA values to interpolate")
    }
    if (missing(xout)) {
        if (n <= 0) {
            stop("aspline requires n >= 1")
        }
        xout <- seq(x[1], x[nx], length = n)
    }
    nout <- length(xout)
    yout <- numeric(nout)
    err <- 0
    if (method == "improved") {
        if (callby == "Fortran") {
            ret <- .Fortran(
                uvip3p,
                as.integer(degree),
                as.integer(nx),
                as.double(x),
                as.double(y),
                as.integer(nout),
                as.double(xout),
                yout = as.double(yout),
                err = as.integer(err),
                PACKAGE = "bnxFortran"
            )
        } else {
            ret <- .C(
                BF_C_uvip3p,
                as.integer(degree),
                as.integer(nx),
                as.double(x),
                as.double(y),
                as.integer(nout),
                as.double(xout),
                yout = as.double(yout),
                err = as.integer(err),
                PACKAGE = "bnxFortran"
            )
        }
    } else {
        if (callby == "Fortran") {
            ret <- .Fortran(
                intrpl,
                as.integer(nx),
                as.double(x),
                as.double(y),
                as.integer(nout),
                as.double(xout),
                yout = as.double(yout),
                err = as.integer(err),
                PACKAGE = "bnxFortran"
            )
        } else {
            ret <- .C(
                BF_C_intrpl,
                as.integer(nx),
                as.double(x),
                as.double(y),
                as.integer(nout),
                as.double(xout),
                yout = as.double(yout),
                err = as.integer(err),
                PACKAGE = "bnxFortran"
            )
        }
    }
    err <- max(0, min(ret$err, 10))
    if (err > 0) {
        errl <- c(
            "Insufficient number of data points",
            "No desired points",
            "Two data points identical or out of sequence",
            "undefined error code",
            "undefined error code",
            "identical x values",
            "x values out of sequence",
            "undefined error code",
            "undefined err
            or code",
            "internal error in Akima Fortran code"
        )
        warning(errl[err])
    }
    list(x = xout, y = ret$yout)
}
