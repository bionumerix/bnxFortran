# nocov start

##>--------------------------------------------------------------------------<##

#' Callable Interface Function in \strong{bnxFortran} Package
#'
#' All callable functions can be called directly from other package source code.
#' For details see the details of respective functions listed below. Function
#' argument validation, except otherwise stated, shall usually be done by the
#' caller.
#'
#' @name bnxFortran-callable
#' @family interfaces
#' @family callable
#' @keywords internal
NULL

##>--------------------------------------------------------------------------<##


##>--------------------------------------------------------------------------<##

#' Akima Splines C Callable Interface: ACM 433
#'
#' @name BF_C_intrpl
#' @family callable
#' @family akima-callable
#' @usage BF_C_intrpl(n, x, y, rn, rx, ry, err)
#' @param n An integer scalar from e.g. \code{as.integer()}. The number of input
#'   data points. Must be 2 or greater.
#' @param x An double vector from e.g. \code{as.double()}. A numeric vector with
#'   the x-values (abscissas) of input data points in ascending order.
#' @param y An double vector from e.g. \code{as.double()}. A numeric vector with
#'   the y-values (ordinates) of input data points.
#' @param rn An integer scalar from e.g. \code{as.integer()}. The number of
#'   points at which interpolation of the y-value (ordinate) is desired. Must be
#'   1 or greater.
#' @param rx An double vector from e.g. \code{as.double()}. A vector of length
#'   \code{rn} for the x-values (abscissas) of desired points.
#' @param ry An double vector from e.g. \code{as.double()}. A vector of length
#'   \code{rn} where the interpolated y-values (ordinates) are to be displayed.
#' @param err An integer scalar from e.g. \code{as.integer()}. A variable to
#'   store an error code.
#' @details For details see: \code{\link[=aspline-interface]{.aspline}}.
#' @section Symbols: \code{BF_C_intrpl}
#' @section Callable: The callable function is defined in a C header file as
#'   follows: \cr \emph{int(*BF_C_intrpl)(int *n, double *x, double *y, int *rn,
#'   double *rx, double *ry, int *err);} \cr\cr Within the \code{R_init_...}
#'   function, the callable function is imported via \cr \emph{BF_C_intrpl =
#'   (int(*)(int*, double*, double*, int*, double*, double*, int*))
#'   R_GetCCallable("bnxFortran", "BF_C_intrpl");}.
NULL

#' Akima Splines C Callable Interface: ACM 697
#'
#' @name BF_C_uvip3p
#' @family callable
#' @family akima-callable
#' @usage BF_C_uvip3p(np, n, x, y, rn, rx, ry, err)
#' @param n An integer scalar from e.g. \code{as.integer()}. The number of input
#'   data points. Must be 2 or greater.
#' @param x An double vector from e.g. \code{as.double()}. A numeric vector with
#'   the x-values (abscissas) of input data points in ascending order.
#' @param y An double vector from e.g. \code{as.double()}. A numeric vector with
#'   the y-values (ordinates) of input data points.
#' @param rn An integer scalar from e.g. \code{as.integer()}. The number of
#'   points at which interpolation of the y-value (ordinate) is desired. Must be
#'   1 or greater.
#' @param rx An double vector from e.g. \code{as.double()}. A vector of length
#'   \code{rn} for the x-values (abscissas) of desired points.
#' @param ry An double vector from e.g. \code{as.double()}. A vector of length
#'   \code{rn} where the interpolated y-values (ordinates) are to be displayed.
#' @param err An integer scalar from e.g. \code{as.integer()}. A variable to
#'   store an error code.
#' @param np An R integer scalar from e.g. \code{as.integer()}. The degree of
#'   the polynomials for the interpolating function.
#' @details For details see: \code{\link[=aspline-interface]{.aspline}}.
#' @section Symbols: \code{BF_C_uvip3p}
#' @section Callable: The callable function is defined in a C header file as
#'   follows: \cr \emph{int(*BF_C_uvip3p)(int *np, int *n, double *x, double *y,
#'   int *rn, double *rx, double *ry, int *err);} \cr\cr Within the
#'   \code{R_init_...} function, the callable function is imported via \cr
#'   \emph{BF_C_uvip3p = (int(*)(int*, int*, double*, double*, int*, double*,
#'   double*, int*)) R_GetCCallable("bnxFortran", "BF_C_uvip3p");}
NULL

##>--------------------------------------------------------------------------<##


##>--------------------------------------------------------------------------<##

#' Non-Negative Least Squares (NNLS) C Callable Interface
#'
#' @name BF_C_nnls
#' @family callable
#' @family nnls-callable
#' @usage BF_C_nnls(A, MDA, M, N, B, X, RNORM, W, ZZ, INDEX, MODE, NSETP)
#' @param A An double vector from e.g. \code{as.double()}. The input matrix
#'   \code{A} as linear array. On entry contains the \code{M*N} matrix. On exit
#'   contains the product matrix \code{Q*A}, where \code{Q} is an \code{M} by
#'   \code{N} orthogonal matrix generated within the Fortran routine.
#' @param MDA An integer scalar from e.g. \code{as.integer()}. The first
#'   dimensioning parameter for \code{A}, i.e. \code{nrow(A)}.
#' @param M An integer scalar from e.g. \code{as.integer()}. The number of rows
#'   of \code{A}, i.e. \code{nrow(A)}.
#' @param N An integer scalar from e.g. \code{as.integer()}. The number of
#'   columns of \code{A}, i.e. \code{ncol(A)}.
#' @param B An double vector from e.g. \code{as.double()}. An \code{length(N)}
#'   vector. On entry contains the \code{N} vector. On exit contains \code{Q*B}.
#' @param X An double vector from e.g. \code{as.double()}. An \code{length(N)}
#'   vector. On entry, need to be initialized with \code{0}. On exit contains
#'   the solution.
#' @param RNORM An double scalar from e.g. \code{as.double()}. The Euclidean
#'   norm of the residual array.
#' @param W An double vector from e.g. \code{as.double()}. An \code{length(N)}
#'   vector as working space.
#' @param ZZ An double vector from e.g. \code{as.double()}. An \code{length(M)}
#'   vector as working space.
#' @param INDEX An integer vector from e.g. \code{as.integer()}. An
#'   \code{length(N)} vector.
#' @param MODE An integer scalar from e.g. \code{as.integer()}. The
#'   success-failure flag as follows: 1 = solution computed successfully, 2 =
#'   bad dimensions, 3 = iteration count exceeded.
#' @param NSETP An integer scalar from e.g. \code{as.integer()}. The number of
#'   elements that are not bound at zero.
#' @details For details see: \code{\link[=nnls-interface]{.nnls}} and the
#'   Fortran source \code{src/nnls.f}.
#' @section Symbols: \code{BF_C_nnls}
#' @section Callable: The callable function is defined in a C header file as
#'   follows: \cr \emph{int(*BF_C_nnls)(double *A, int *MDA, int *M, int *N,
#'   double *B, double *X, double *RNORM, double *W, double *ZZ, int *INDEX, int
#'   *MODE, int *NSETP);} \cr\cr Within the \code{R_init_...} function, the
#'   callable function is imported via \cr \emph{BF_C_nnls = (int(*)(double*,
#'   int*, int*, int*, double*, double*, double*, double*, double*, int*, int*,
#'   int*)) R_GetCCallable("bnxFortran", "BF_C_nnls");}
NULL

##>--------------------------------------------------------------------------<##

# nocov end
