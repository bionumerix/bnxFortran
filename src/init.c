/*!*****************************************************************************
 * @file
 * @brief R2C-Interface: entry point definitions and routine registrations.
 * @authors Dirk Steinhauser and R Core Team.
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
#include "init.h"
#include "args.h"
#include "call.h"
//>--------------------------------------------------------------------------<//


//>-SPECIAL------------------------------------------------------------------<//
#if _MSC_VER >= 1000
__declspec(dllexport)
#endif
//>--------------------------------------------------------------------------<//


//>-MACROS-------------------------------------------------------------------<//

/**
 * Convenience macro for entry point definition for \c .Call interface.
 */
#define PD_CDEF(name)                                                          \
    { #name, (DL_FUNC)&name, sizeof(name##_t) / sizeof(name##_t[0]), name##_t }
/**
 * Convenience macro for entry point definition for \c .Fortran interface.
 */
#define PD_FDEF(name, args)                                                    \
    { #name, (DL_FUNC)&F77_SUB(name), sizeof(args) / sizeof(args[0]), args }
/**
 * Convenience macro for registering callable functions.
 */
#define PD_RDEF(name) R_RegisterCCallable("bnxFortran", #name, (DL_FUNC)name)

//>--------------------------------------------------------------------------<//


//>-EntryPoints--------------------------------------------------------------<//

#ifndef PKG_PRAGMAX
#  if __GNUC__
#    pragma GCC diagnostic push
#    pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#  endif
#endif

/**
 * Entry points for \c .Call interface.
 */
static const R_CMethodDef CEntries[] = {
    // func
    PD_CDEF(BF_C_nnls),
    PD_CDEF(BF_C_intrpl),
    PD_CDEF(BF_C_uvip3p),
    // null
    {NULL, NULL, 0}
};

/**
 * Entry points for \c .Fortran interface.
 */
static const R_FortranMethodDef FortEntries[] = {
    // func
    PD_FDEF(nnls, BF_C_nnls_t),
    PD_FDEF(intrpl, BF_C_intrpl_t),
    PD_FDEF(uvip3p, BF_C_uvip3p_t),
    // null
    {NULL, NULL, 0}
};

#ifndef PKG_PRAGMAX
#  if __GNUC__
#    pragma GCC diagnostic pop
#  endif
#endif

//>--------------------------------------------------------------------------<//


//>-Registration-------------------------------------------------------------<//

void attribute_visible R_init_bnxFortran(DllInfo *info)
{
    // Register routines for .C, .Call, and .Fortran interface.
    R_registerRoutines(info, CEntries, NULL, FortEntries, NULL);
    // If correct entry point not found, signal an error.
    R_useDynamicSymbols(info, FALSE);
    R_forceSymbols(info, TRUE); // call via .Call(.NAME, ...) w/o '"'
    // Register C routines to be called from other packages.
    PD_RDEF(BF_C_nnls);
    PD_RDEF(BF_C_intrpl);
    PD_RDEF(BF_C_uvip3p);
}

#ifndef PKG_PRAGMAX
#  if __GNUC__
#    pragma GCC diagnostic push
#    pragma GCC diagnostic ignored "-Wunused-parameter"
#  endif
#endif
// # nocov start
void attribute_visible R_unload_bnxFortran(DllInfo *info)
{
  // Release resources.
}
// # nocov end
#ifndef PKG_PRAGMAX
#  if __GNUC__
#    pragma GCC diagnostic pop
#  endif
#endif

//>--------------------------------------------------------------------------<//


//>-UNDEF--------------------------------------------------------------------<//
#undef _CDEF
#undef _FDEF
#undef _CALLDEF
#undef _RREGDEF
//>--------------------------------------------------------------------------<//
