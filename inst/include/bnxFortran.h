/*!*****************************************************************************
 * @file
 * @brief     Assembly header for R package C/C++ interface facilities.
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

#ifndef BNXFORTRAN_H
#define BNXFORTRAN_H

//>-HEADERS------------------------------------------------------------------<//
#if __GNUC__
#  pragma GCC diagnostic push
#  pragma GCC diagnostic ignored "-Wstrict-prototypes"
#  pragma GCC diagnostic ignored "-Wredundant-decls"
#  pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>
#include <R_ext/Rdynload.h>
#if __GNUC__
#  pragma GCC diagnostic pop
#endif
//>--------------------------------------------------------------------------<//

//>-CALLABLES----------------------------------------------------------------<//
//  FROM: ' \*[a-z]*[,][\s]'   TO: '*,'
/*! @brief C API of Lawson's and Hanson's non-negative least squares (NNLS).
 *  @copydetails nnls()
 */
int
(*BF_C_nnls)(double *, int *, int *, int *, double *, double *, double *,
             double *, double *, int *, int *, int *);

/*! @brief C API of interpolating standard Akima splines: ACM 433.
 *  @copydetails BF_C_intrpl(int *n, double *x, double *y, int *rn, double *rx, 
 *      double *ry, int *err)
 */
int
(*BF_C_intrpl)(int *, double *, double *, int *, double *, double *, int *);

/*! @brief C API of interpolating optimised Akima splines: ACM 697.
 *  @copydetails BF_C_uvip3p(int *np, int *n, double *x, double *y, int *rn, 
 *      double *rx, double *ry, int *err)
 */
int
(*BF_C_uvip3p)(int *, int *, double *, double *, int *, double *, double *, 
               int *);
//>--------------------------------------------------------------------------<//

//>-INTERFACE----------------------------------------------------------------<//
/*! @brief Import macro for C API of Lawson's and Hanson's non-negative least 
 *      squares (NNLS).
 */
#define API_BF_C_nnls                                                          \
    BF_C_nnls = (int(*)(double*,int*,int*,int*,double*,double*,double*,double*,\
        double*,int*,int*,int*)) R_GetCCallable("bnxFortran", "BF_C_nnls")

/*! @brief Import macro for C API of interpolating standard Akima splines: 
 *      ACM 433.
 */
#define API_BF_C_intrpl                                                        \
    BF_C_intrpl = (int(*)(int*,double*,double*,int*,double*,double*,int*))     \
        R_GetCCallable("bnxFortran", "BF_C_intrpl")

/*! @brief Import macro for C API of interpolating optimised Akima splines: 
 *      ACM 697.
 */
#define API_BF_C_uvip3p                                                        \
    BF_C_uvip3p = (int(*)(int*,int*,double*,double*,int*,double*,double*,int*))\
        R_GetCCallable("bnxFortran", "BF_C_uvip3p")
//>--------------------------------------------------------------------------<//

#endif /* BNXFORTRAN_H */
