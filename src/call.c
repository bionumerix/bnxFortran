/*!*****************************************************************************
 * @file
 * @brief R2C-Interface: Fortran wrapper call routines.
 * @authors Dirk Steinhauser.
 * @copyright (C) 2018-2019 Bionumerix (BNX) and authors. \n
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


//>-HEADERS------------------------------------------------------------------<//
#include "call.h"
//>--------------------------------------------------------------------------<//


//>-Wrapper------------------------------------------------------------------<//

int
BF_C_nnls(double *A, int *MDA, int *M, int *N, double *B, double *X,
          double *RNORM, double *W, double *ZZ, int *INDEX, int *MODE, 
          int *NSETP)
{
    return F77_CALL(nnls)(A, MDA, M, N, B, X, RNORM, W, ZZ, INDEX, MODE, NSETP);
}

int
BF_C_intrpl(int *n, double *x, double *y, int *rn, double *rx, double *ry,
            int *err)
{
    return F77_CALL(intrpl)(n, x, y, rn, rx, ry, err);
}

int
BF_C_uvip3p(int *np, int *n, double *x, double *y, int *rn, double *rx,
            double *ry, int *err)
{
    return F77_CALL(uvip3p)(np, n, x, y, rn, rx, ry, err);
}

//>--------------------------------------------------------------------------<//
