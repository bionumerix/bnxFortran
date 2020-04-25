/*!*****************************************************************************
 * @file
 * @brief R2C-Interface: entry point definitions and routine registrations.
 * @authors Dirk Steinhauser and R Core Team.
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

#include "init.h"
#include "args.h"
#include "call.h"

/******************************************************************************\
* Local Utility Macros: Define                                                 *
\******************************************************************************/

/**
 * Convenience macro for entry point definition for \c .Call interface.
 */
// clang-format off
#define PD_CDEF(name)                                                          \
    { #name, (DL_FUNC)&name, sizeof(name##_t) / sizeof(name##_t[0]), name##_t }
// clang-format on

/**
 * Convenience macro for entry point definition for \c .Fortran interface.
 */
// clang-format off
#define PD_FDEF(name, args)                                                    \
    { #name, (DL_FUNC)&F77_SUB(name), sizeof(args) / sizeof(args[0]), args }
// clang-format on

/**
 * Convenience macro for registering callable functions.
 */
// clang-format off
#define PD_RDEF(name) R_RegisterCCallable("bnxFortran", #name, (DL_FUNC)name)
// clang-format on

/******************************************************************************\
* EntryPoints                                                                  *
\******************************************************************************/

// clang-format off
#if defined(EXT_PRAGMA_IGNORE) && (defined(__GNUC__) || defined(__CLANG__))
#  pragma GCC diagnostic push
#  pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#  pragma GCC diagnostic ignored "-Wcast-function-type"
#endif
// clang-format on

/**
 * Entry points for \c .Call interface.
 */
static const R_CMethodDef CEntries[] = {
    // func
    PD_CDEF(BF_C_nnls),
    PD_CDEF(BF_C_intrpl),
    PD_CDEF(BF_C_uvip3p),
    // null
    {NULL, NULL, 0}};

/**
 * Entry points for \c .Fortran interface.
 */
static const R_FortranMethodDef FortEntries[] = {
    // func
    PD_FDEF(nnls, BF_C_nnls_t),
    PD_FDEF(intrpl, BF_C_intrpl_t),
    PD_FDEF(uvip3p, BF_C_uvip3p_t),
    // null
    {NULL, NULL, 0}};

// clang-format off
#if defined(EXT_PRAGMA_IGNORE) && (defined(__GNUC__) || defined(__CLANG__))
#  pragma GCC diagnostic pop
#endif
// clang-format on

/******************************************************************************\
* Registration                                                                 *
\******************************************************************************/

// clang-format off
#if defined(EXT_PRAGMA_IGNORE) && (defined(__GNUC__) || defined(__CLANG__))
#  pragma GCC diagnostic push
#  pragma GCC diagnostic ignored "-Wcast-function-type"
#endif
// clang-format on

void attribute_visible // # nocov start
R_init_bnxFortran(DllInfo *info)
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
} // # nocov end

// clang-format off
#if defined(EXT_PRAGMA_IGNORE) && (defined(__GNUC__) || defined(__CLANG__))
#  pragma GCC diagnostic pop
#endif
// clang-format on

// clang-format off
#if defined(EXT_PRAGMA_IGNORE) && (defined(__GNUC__) || defined(__CLANG__))
#  pragma GCC diagnostic push
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#endif
// clang-format on

void attribute_visible // # nocov start
R_unload_bnxFortran(DllInfo *info)
{
    // Release resources.
} // # nocov end

// clang-format off
#if defined(EXT_PRAGMA_IGNORE) && (defined(__GNUC__) || defined(__CLANG__))
#  pragma GCC diagnostic pop
#endif
// clang-format on

/******************************************************************************\
* Local Utility Macros: Undefine                                               *
\******************************************************************************/

#undef _CDEF
#undef _FDEF
#undef _CALLDEF
#undef _RREGDEF
