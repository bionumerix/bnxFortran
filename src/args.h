/*!*****************************************************************************
 * @file
 * @brief     R2C-Interface: function argument definitions.
 * @authors   Dirk Steinhauser and other contributors.
 * @copyright (C) 2018 - 2019 BioNumeriX (BNX) and authors.
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

#ifndef SRC_ARGS_H_
#define SRC_ARGS_H_

//>-HEADERS------------------------------------------------------------------<//
#include "init.h"
//>--------------------------------------------------------------------------<//

//>-ARGUMENTS/NNLS-----------------------------------------------------------<//
/*! @brief Variable for R's argument type definition for NNLS function.
 */
static R_NativePrimitiveArgType BF_C_nnls_t[12] = {
    REALSXP, /* A     */
    INTSXP,  /* MDA   */
    INTSXP,  /* M     */
    INTSXP,  /* N     */
    REALSXP, /* B     */
    REALSXP, /* X     */
    REALSXP, /* RNORM */
    REALSXP, /* W     */
    REALSXP, /* ZZ    */
    INTSXP,  /* INDEX */
    INTSXP,  /* MODE  */
    INTSXP,  /* NSETP */
};
//>--------------------------------------------------------------------------<//

//>-ARGUMENTS/Akima----------------------------------------------------------<//
/*! @brief Variable for R's argument type definition for akima spline ACM 433.
 */
static R_NativePrimitiveArgType BF_C_intrpl_t[7] = {
    INTSXP,  /* L,  */
    REALSXP, /* X,  */
    REALSXP, /* Y,  */
    INTSXP,  /* N,  */
    REALSXP, /* U,  */
    REALSXP, /* V,  */
    INTSXP   /* ERR */
};

/*! @brief Variable for R's argument type definition for akima spline ACM 697.
 */
static R_NativePrimitiveArgType BF_C_uvip3p_t[8] = {
    INTSXP,  /* NP, */
    INTSXP,  /* ND, */
    REALSXP, /* XD, */
    REALSXP, /* YD, */
    INTSXP,  /* NI, */
    REALSXP, /* XI, */
    REALSXP, /* YI, */
    INTSXP   /* ERR */
};
//>--------------------------------------------------------------------------<//

#endif /* SRC_ARGS_H_ */
