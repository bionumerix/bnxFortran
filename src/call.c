/*!*****************************************************************************
 * @file
 * @brief     R2C-Interface: Fortran wrapper call routines.
 * @authors   Dirk Steinhauser and other contributors.
 * @copyright (C) 2018 - 2019 BioNumeriX (BNX) and authors. \n
 *      Third party copyrights are property of their respective owners.
 * @association
 *      This file is part of the bnxFortran R package.
 * @license
 *      GPL (>= 3): Distributed under GNU General Public License version 3 or
 *      higher (GPL >=3). \n
 *      This program is free software; you can redistribute it and/or modify it
 *      under the terms of the GNU General Public License as published by the
 *      Free Software Foundation; either version 3 of the License, or (at your
 *      option) any later version. \n
 *      This program is distributed in the hope that it will be useful, but
 *      WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 *      General Public License for more details. \n
 *      You should have received a copy of the GNU General Public License along
 *      with this program. If not, see <http://www.gnu.org/licenses/>.
*******************************************************************************/

//>-HEADERS------------------------------------------------------------------<//
#include "call.h"
//>--------------------------------------------------------------------------<//

//>-Wrapper------------------------------------------------------------------<//
/*! @brief C wrapper of Lawson's and Hanson's non-negative least squares (NNLS).
 *  @copydetails nnls()
 */
int
BF_C_nnls(double *A, int *MDA, int *M, int *N, double *B, double *X,
          double *RNORM, double *W, double *ZZ, int *INDEX, int *MODE, 
          int *NSETP) {
    return F77_CALL(nnls)(A, MDA, M, N, B, X, RNORM, W, ZZ, INDEX, MODE, NSETP);
}

/*! @brief C wrapper for interpolating standard Akima splines: ACM 433.
 *  @param[in] n The number of input data points. Must be 2 or greater.
 *  @param[in] x An array of dimension \c l storing the x-values (abscissas) of
 *      input data points in ascending order.
 *  @param[in] y An array of dimension \c l storing the y-values (ordinates) of
 *      input data points.
 *  @param[in] rn The number of points at which interpolation of the y-value
 *      (ordinate) is desired. Must be 1 or greater.
 *  @param[in] rx An array of dimension \c rn for the x-values (abscissas) of
 *      desired points.
 *  @param[in,out] ry An array of dimension \c rn where the interpolated
 *      y-values (ordinates) are to be displayed.
 *  @param[in,out] err An error code.
 */
int
BF_C_intrpl(int *n, double *x, double *y, int *rn, double *rx, double *ry,
            int *err) {
    return F77_CALL(intrpl)(n, x, y, rn, rx, ry, err);
}

/*! @brief C wrapper for interpolating optimised Akima splines: ACM 697.
 *  @param[in] np The degree of the polynomials for the interpolating function.
 *  @copydetails BF_C_intrpl(int *n, double *x, double *y, int *rn, double *rx, 
 *      double *ry, int *err)
 */
int
BF_C_uvip3p(int *np, int *n, double *x, double *y, int *rn, double *rx,
            double *ry, int *err) {
    return F77_CALL(uvip3p)(np, n, x, y, rn, rx, ry, err);
}
//>--------------------------------------------------------------------------<//
