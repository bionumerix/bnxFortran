/*!*****************************************************************************
 * @file
 * @brief R2C-Interface: entry point definitions and routine registrations.
 * @authors Dirk Steinhauser and other contributors.
 * @copyright (C) 2018 - 2019 Bionumerix (BNX) and authors. \n
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

#ifndef SRC_INIT_H
#define SRC_INIT_H

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
#include <R_ext/Applic.h>
#include <R_ext/Lapack.h>
#include <R_ext/Rdynload.h>
#include <R_ext/Visibility.h>
#if __GNUC__
#  pragma GCC diagnostic pop
#endif
//>--------------------------------------------------------------------------<//

//>-Registration-------------------------------------------------------------<//
void attribute_visible R_init_bnxFortran(DllInfo*);
void attribute_visible R_unload_bnxFortran(DllInfo*);
//>--------------------------------------------------------------------------<//

#endif /* SRC_INIT_H */
