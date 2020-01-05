/*!*****************************************************************************
 * @file
 * @brief Assembly header for R package C/C++ interface facilities.
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

#ifndef BNXFORTRAN_H
#define BNXFORTRAN_H


//>-HEADERS------------------------------------------------------------------<//
#include <R_ext/Rdynload.h>
//>--------------------------------------------------------------------------<//


//>-CALLABLES----------------------------------------------------------------<//

//  FROM: ' \*[a-z]*[,][\s]'   TO: '*,'
/**
 * C API of Lawson's and Hanson's non-negative least squares (NNLS).
 * 
 * @copydetails nnls()
 */
int
(*BF_C_nnls)(double*, int*, int*, int*, double*, double*, double*, double*, 
             double*, int*, int*, int*);

/**
 * C API of interpolating standard Akima splines: ACM 433.
 * 
 * @copydetails BF_C_intrpl(int *n, double *x, double *y, int *rn, double *rx, 
 *      double *ry, int *err)
 */
int
(*BF_C_intrpl)(int*, double*, double*, int*, double*, double*, int*);

/**
 * C API of interpolating optimised Akima splines: ACM 697.
 * 
 * @copydetails BF_C_uvip3p(int *np, int *n, double *x, double *y, int *rn, 
 *      double *rx, double *ry, int *err)
 */
int
(*BF_C_uvip3p)(int*, int*, double*, double*, int*, double*, double*, int*);

//>--------------------------------------------------------------------------<//


//>-INTERFACE----------------------------------------------------------------<//

/**
 * Import macro for C API of Lawson's and Hanson's non-negative least squares.
 */
#define API_BF_C_nnls                                                          \
    BF_C_nnls = (int(*)(double*,int*,int*,int*,double*,double*,double*,double*,\
        double*,int*,int*,int*)) R_GetCCallable("bnxFortran", "BF_C_nnls")

/**
 * Import macro for C API of interpolating standard Akima splines: ACM 433.
 */
#define API_BF_C_intrpl                                                        \
    BF_C_intrpl = (int(*)(int*,double*,double*,int*,double*,double*,int*))     \
        R_GetCCallable("bnxFortran", "BF_C_intrpl")

/**
 * Import macro for C API of interpolating optimised Akima splines: ACM 697.
 */
#define API_BF_C_uvip3p                                                        \
    BF_C_uvip3p = (int(*)(int*,int*,double*,double*,int*,double*,double*,int*))\
        R_GetCCallable("bnxFortran", "BF_C_uvip3p")

//>--------------------------------------------------------------------------<//


#endif /* BNXFORTRAN_H */
