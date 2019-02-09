context("nnls")
library(nnls)

test_that("nnls", {
    ## simulate a matrix A
    ## with 3 columns, each containing an exponential decay
    t <- seq(0, 2, by = .04)
    k <- c(.5, .6, 1)
    A <- matrix(nrow = 51, ncol = 3)
    Acolfunc <- function(k, t) exp(-k*t)
    for (i in 1:3) A[,i] <- Acolfunc(k[i],t)
    #
    ## simulate a matrix X
    ## with 3 columns, each containing a Gaussian shape
    ## the Gaussian shapes are non-negative
    X <- matrix(nrow = 51, ncol = 3)
    wavenum <- seq(18000,28000, by = 200)
    location <- c(25000, 22000, 20000)
    delta <- c(3000,3000,3000)
    Xcolfunc <- function(wavenum, location, delta) {
        exp( -log(2) * (2 * (wavenum - location)/delta)^2)
    }
    for (i in 1:3) X[,i] <- Xcolfunc(wavenum, location[i], delta[i])
    #
    ## set seed for reproducibility
    set.seed(3300)
    #
    ## simulated data is the product of A and X with some
    ## spherical Gaussian noise added
    matdat <- A %*% t(X) + .005 * rnorm(nrow(A) * nrow(X))
    #
    ## estimate the rows of X using NNLS criteria
    nnls_sol <- function(matdat, A, fun, ...) {
        X <- matrix(0, nrow = 51, ncol = 3)
        for (i in 1:ncol(matdat))
            X[i,] <- coef(fun(A,matdat[,i],...))
        X
    }
    #
    orig <- nnls_sol(matdat, A, fun = nnls::nnls)
    cfun <- nnls_sol(matdat, A, fun = .nnls)
    ffun <- nnls_sol(matdat, A, fun = .nnls, callby = "F")
    expect_identical(orig, cfun)
    expect_identical(orig, ffun)
})
