/*!*****************************************************************************
 * @file
 * @brief R2C-Interface: Fortran wrapper call routines.
 * @authors Dirk Steinhauser.
 * @copyright (C) 2018-2020 Bionumerix (BNX) and authors. \n
 *      Third party copyrights are property of their respective owners.
 * @license
 *      This file is part of bnxFortran.
 *      \n
 *      bnxFortran is free software: you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation, either version 3 of the License, or
 *      (at your option) any later version.
 *      \n
 *      bnxFortran is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *      \n
 *      You should have received a copy of the GNU General Public License
 *      along with bnxFortran.  If not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************/

#ifndef SRC_CALL_H
#define SRC_CALL_H

#include <R_ext/RS.h> // for F77_NAME, F77_CALL (in .c)

/******************************************************************************\
* Wrapper                                                                      *
\******************************************************************************/

/**
 * @brief C wrapper of Lawson's and Hanson's non-negative least squares (NNLS).
 * @copydetails nnls()
 */
int //
BF_C_nnls(double *A, int *MDA, int *M, int *N, double *B, double *X,
          double *RNORM, double *W, double *ZZ, int *INDEX, int *MODE,
          int *NSETP);

/**
 * @brief C wrapper for interpolating standard Akima splines: ACM 433.
 * @param[in] n The number of input data points. Must be 2 or greater.
 * @param[in] x An array of dimension \c l storing the x-values (abscissas) of
 *      input data points in ascending order.
 * @param[in] y An array of dimension \c l storing the y-values (ordinates) of
 *      input data points.
 * @param[in] rn The number of points at which interpolation of the y-value
 *      (ordinate) is desired. Must be 1 or greater.
 * @param[in] rx An array of dimension \c rn for the x-values (abscissas) of
 *      desired points.
 * @param[in,out] ry An array of dimension \c rn where the interpolated
 *      y-values (ordinates) are to be displayed.
 * @param[in,out] err An error code.
 */
int //
BF_C_intrpl(int *n, double *x, double *y, int *rn, double *rx, double *ry,
            int *err);

/**
 * @brief C wrapper for interpolating optimised Akima splines: ACM 697.
 * @param[in] np The degree of the polynomials for the interpolating function.
 * @copydetails BF_C_intrpl(int *n, double *x, double *y, int *rn, double *rx, 
 *      double *ry, int *err)
 */
int //
BF_C_uvip3p(int *np, int *n, double *x, double *y, int *rn, double *rx,
            double *ry, int *err);

/******************************************************************************\
* Extern: NNLS                                                                 *
\******************************************************************************/

/**
 * @brief Fortran function of Lawson's and Hanson's non-negative least squares 
 *      (NNLS).
 * @details This Fortran function is located in file 'xf77.nnls.f' taken from R
 *      package 'nnls' by Katharine M. Mullen and Ivo H. M. van Stokkum (2012).
 *      R package version 1.4. http://CRAN.R-project.org/package=nnls. This is
 *      an R interface to the Fortran77 code distributed with the book
 *      referenced below by Lawson CL, Hanson RJ (1995), obtained from Netlib
 *      (file 'lawson-hanson/all'), with a trivial modification to return the
 *      variable NSETP (taken from Mullen and Stokkum).
 * @param A A member for \c A, matrix as linear array. On entry contains the
 *      \c M*N matrix. On exit contains the product matrix \c Q*A, where Q is
 *      an \c M by \c N orthogonal matrix generated within the Fortran routine.
 * @param MDA The first dimensioning parameter for \c A, usually the no. of
 *      rows (from R).
 * @param M The number of rows of \c A (from R).
 * @param N The number of columns of \c A (from R).
 * @param B On entry contains the \c N vector. On exit contains \c Q*B.
 * @param X On entry, need to be initialised with \c 0. On exit contains the
 *      solution.
 * @param RNORM The Euclidean norm of the residual array.
 * @param W An N - array of working space. On exit will contain dual solution
 *      vector. \c W will satisfy W(I) = 0. For all I IN set P and W(I) .LE. 0
 *      FOR ALL I IN set Z.
 * @param ZZ A \c M - array of working space.
 * @param INDEX An at least \c N - array.
 * @param MODE  The success-failure mode as follows: 1 = solution computed
 *      successfully, 2 = dimensions of problem are bad (M<=0 or N<=0), 3 =
 *      iteration count exceeded, i.e. more than 3*N iterations.
 * @param NSETP The number of elements that are not bound at zero.
 * @attention \c C language is using row-major order arrangement of
 *      multidimensional arrays in linear memory storage. \c R and F use
 *      column-major order arrangement. The caller must take that into account.
 */
// clang-format off
extern int
F77_NAME(nnls)(double *A, int *MDA, int *M, int *N, double *B, double *X, 
               double *RNORM, double *W, double *ZZ, int *INDEX, int *MODE, 
               int *NSETP);
// clang-format on

/******************************************************************************\
* Extern: Akima                                                                *
\******************************************************************************/

/**
 * @brief Fortran function for interpolating standard Akima splines: ACM 433.
 * @details This Fortran function is located in file 'xf77.akima433.f' of the
 *      'akima' package by Hiroshi Akima and Albrecht Gebhardt et al. (2015).
 *      R package version 0.6-2. http://CRAN.R-project.org/package=akima
 * @param[in] l The number of input data points. Must be 2 or greater.
 * @param[in] x An array of dimension \c l storing the x-values (abscissas) of
 *      input data points in ascending order.
 * @param[in] y An array of dimension \c l storing the y-values (ordinates) of
 *      input data points.
 * @param[in] n The number of points at which interpolation of the y-value
 *      (ordinate) is desired. Must be 1 or greater.
 * @param[in] u An array of dimension \c n storing the x-values (abscissas) of
 *      desired points.
 * @param[in,out] v An array of dimension \c n where the interpolated y-values
 *      (ordinates) are to be displayed.
 * @param[in,out] err An error code.
 */
// clang-format off
extern int
F77_NAME(intrpl)(int *l, double *x, double *y, int *n, double *u, double *v, 
                 int *err);
// clang-format on

/**
 * @brief Fortran function for interpolating optimised Akima splines: ACM 697.
 * @details This Fortran function is located in file 'xf77.akima697.f' of the
 *      'akima' package by Hiroshi Akima and Albrecht Gebhardt et al. (2015).
 *      R package version 0.6-2. http://CRAN.R-project.org/package=akima
 * @param[in] np The degree of the polynomials for the interpolating function.
 * @param[in] nd The number of input data points. Must be 2 or greater.
 * @param[in] xd An array of dimension \c nd, containing the abscissas of the
 *      input data points. Must be in a monotonic increasing order.
 * @param[in] yd An array of dimension \c nd, containing the ordinates of the
 *      input data points.
 * @param[in] ni Number of points for which interpolation is desired. Must be
 *      equal to 1 or greater.
 * @param[in] xi An array of dimension \c ni, containing the abscissas of the
 *      desired points.
 * @param[in,out] yi An array of dimension \c ni where the ordinates of the
 *      desired points are to be stored.
 * @param[in,out] err An error code.
 */
// clang-format off
extern int
F77_NAME(uvip3p)(int *np, int *nd, double *xd, double *yd, int *ni, double *xi, 
                 double *yi, int *err);
// clang-format on

#endif /* SRC_CALL_H */
