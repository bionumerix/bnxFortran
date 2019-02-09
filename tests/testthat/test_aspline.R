context("aspline")
library(akima)

test_that("aspline-1", {
    ## regular spaced data
    x <- 1:10
    y <- c(rnorm(5), c(1,1,1,1,3))
    xnew <- seq(-1, 11, 0.1)
    #
    orig <-  aspline(x, y, xnew)
    cfun <- .aspline(x, y, xnew)
    ffun <- .aspline(x, y, xnew, callby = "F")
    expect_identical(orig, cfun)
    expect_identical(orig, ffun)
    #
    orig <-  aspline(x, y, xnew, method = "improved")
    cfun <- .aspline(x, y, xnew, method = "improved")
    ffun <- .aspline(x, y, xnew, method = "improved", callby = "F")
    expect_identical(orig, cfun)
    expect_identical(orig, ffun)
    #
    orig <-  aspline(x, y, xnew, method = "improved", degree = 10)
    cfun <- .aspline(x, y, xnew, method = "improved", degree = 10)
    ffun <- .aspline(x, y, xnew, method = "improved", degree = 10, callby = "F")
    expect_identical(orig, cfun)
    expect_identical(orig, ffun)
})

test_that("aspline-2", {
    ## irregular spaced data
    x <- sort(runif(10, max = 10))
    y <- c(rnorm(5), c(1,1,1,1,3))
    xnew <- seq(-1, 11, 0.1)
    #
    orig <-  aspline(x, y, xnew)
    cfun <- .aspline(x, y, xnew)
    ffun <- .aspline(x, y, xnew, callby = "F")
    expect_identical(orig, cfun)
    expect_identical(orig, ffun)
    #
    orig <-  aspline(x, y, xnew, method = "improved")
    cfun <- .aspline(x, y, xnew, method = "improved")
    ffun <- .aspline(x, y, xnew, method = "improved", callby = "F")
    expect_identical(orig, cfun)
    expect_identical(orig, ffun)
    #
    orig <-  aspline(x, y, xnew, method = "improved", degree = 10)
    cfun <- .aspline(x, y, xnew, method = "improved", degree = 10)
    ffun <- .aspline(x, y, xnew, method = "improved", degree = 10, callby = "F")
    expect_identical(orig, cfun)
    expect_identical(orig, ffun)
})

test_that("aspline-3", {
    ## an example of Akima, 1991
    x <- c(-3, -2, -1, 0,  1,  2, 2.5, 3)
    y <- c( 0,  0,  0, 0, -1, -1, 0,   2)
    #
    orig <-  aspline(x, y, n = 200)
    cfun <- .aspline(x, y, n = 200)
    ffun <- .aspline(x, y, n = 200, callby = "F")
    expect_identical(orig, cfun)
    expect_identical(orig, ffun)
    #
    orig <-  aspline(x, y, n = 200, method = "improved")
    cfun <- .aspline(x, y, n = 200, method = "improved")
    ffun <- .aspline(x, y, n = 200, method = "improved", callby = "F")
    expect_identical(orig, cfun)
    expect_identical(orig, ffun)
    #
    orig <-  aspline(x, y, n = 200, method = "improved", degree = 10)
    cfun <- .aspline(x, y, n = 200, method = "improved", degree = 10)
    ffun <- .aspline(x, y, n = 200, method = "improved", degree = 10,
                     callby = "F")
    expect_identical(orig, cfun)
    expect_identical(orig, ffun)
})
