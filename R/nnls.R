#' The Lawson-Hanson NNLS Implemention of Non-Negative Least Squares
#'
#' An R interface to the Lawson-Hanson NNLS implementation of an algorithm for
#' non-negative linear least squares. For details see \code{\link[nnls]{nnls}}.
#'
#' @name nnls-interface
#' @inheritParams nnls::nnls
#' @inheritParams argCallby
#' @author Credit: This function is based on the \code{\link[nnls]{nnls}}
#'   functions from \strong{package::\link[nnls]{nnls-package}} by Katharine M.
#'   Mullen and Ivo H. M. van Stokkum. Some minor modifications have been made
#'   to evaluate the results from the callable interface routines implemented
#'   within this packages.
#' @seealso \code{\link[nnls]{nnls}}
#' @examples
#' ## simulate a matrix A
#' ## with 3 columns, each containing an exponential decay
#'  t <- seq(0, 2, by = .04)
#'  k <- c(.5, .6, 1)
#'  A <- matrix(nrow = 51, ncol = 3)
#'  Acolfunc <- function(k, t) exp(-k*t)
#'  for (i in 1:3) A[,i] <- Acolfunc(k[i],t)
#'
#' ## simulate a matrix X
#' ## with 3 columns, each containing a Gaussian shape
#' ## the Gaussian shapes are non-negative
#'  X <- matrix(nrow = 51, ncol = 3)
#'  wavenum <- seq(18000,28000, by=200)
#'  location <- c(25000, 22000, 20000)
#'  delta <- c(3000,3000,3000)
#'  Xcolfunc <- function(wavenum, location, delta)
#'    exp( - log(2) * (2 * (wavenum - location)/delta)^2)
#'  for (i in 1:3) X[,i] <- Xcolfunc(wavenum, location[i], delta[i])
#'
#' ## set seed for reproducibility
#'  set.seed(3300)
#'
#' ## simulated data is the product of A and X with some
#' ## spherical Gaussian noise added
#'  matdat <- A %*% t(X) + .005 * rnorm(nrow(A) * nrow(X))
#'
#' ## estimate the rows of X using NNLS criteria
#'  nnls_sol <- function(matdat, A, fun, ...) {
#'    X <- matrix(0, nrow = 51, ncol = 3)
#'    for (i in 1:ncol(matdat))
#'       X[i,] <- coef(fun(A,matdat[,i],...))
#'    X
#'  }
#'
#'  orig <- nnls_sol(matdat, A, fun = nnls::nnls)
#'  cfun <- nnls_sol(matdat, A, fun = .nnls)
#'  ffun <- nnls_sol(matdat, A, fun = .nnls, callby = "F")
#'  stopifnot(identical(orig, cfun))
#'  stopifnot(identical(orig, ffun))
#' @export
.nnls <- function(A, b, callby = c("C", "Fortran")) {
    callby <- match.arg(callby)
    MDA <- M <- nrow(A)
    N <- ncol(A)
    RNORM <- MODE <- NSETP <- 0
    W <- INDEX <- X <- rep(0, N)
    ZZ <- rep(0, M)
    if (callby == "Fortran") {
        sol <- .Fortran(
            nnls,
            A = as.numeric(A),
            MDA = as.integer(MDA),
            M = as.integer(M),
            N = as.integer(N),
            B = as.numeric(b),
            X = as.numeric(X),
            RNORM = as.numeric(RNORM),
            W = as.numeric(W),
            ZZ = as.numeric(ZZ),
            INDEX = as.integer(INDEX),
            MODE = as.integer(MODE),
            NSETP = as.integer(NSETP),
            PACKAGE = "bnxFortran"
        )
    } else {
        sol <- .C(
            BF_C_nnls,
            A = as.numeric(A),
            MDA = as.integer(MDA),
            M = as.integer(M),
            N = as.integer(N),
            B = as.numeric(b),
            X = as.numeric(X),
            RNORM = as.numeric(RNORM),
            W = as.numeric(W),
            ZZ = as.numeric(ZZ),
            INDEX = as.integer(INDEX),
            MODE = as.integer(MODE),
            NSETP = as.integer(NSETP),
            PACKAGE = "bnxFortran"
        )
    }
    fitted <- A %*% sol$X
    resid <- b - fitted
    index <- sol$INDEX
    nsetp <- sol$NSETP
    if (nsetp > 0) {
        passive <- index[1:nsetp]
    } else {
        passive <- vector()
    }
    if (nsetp == N) {
        bound <- vector()
    } else {
        bound <- index[(nsetp + 1):N]
    }
    nnls.out <- list(
        x = sol$X,
        deviance = sol$RNORM ^ 2,
        residuals = resid,
        fitted = fitted,
        mode = sol$MODE,
        passive = passive,
        bound = bound,
        nsetp = nsetp
    )
    class(nnls.out) <- "nnls"
    nnls.out
}
