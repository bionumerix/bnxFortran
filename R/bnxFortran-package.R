#>-package--------------------------------------------------------------------<#

#' bnxFortran: BNX Interface Package for R2C Callable Fortran Routines
#'
#' The 'bnxFortran' package provides some C functions that wrap Fortran
#' algorithms. These interface functions are implemented here to be called
#' directly from the C or C++ source code level of other R packages.
#'
#' @name bnxFortran
#' @details \bold{No S4 methodology allowed here!}
#' @details See documentation for overview and details.
#' @author Dirk Steinhauser <\email{steinhauser@@bionumerix.org}>
#' @author See \code{DESCRIPTION} and \code{README.md} for contributors.
#' @references See documentation for overview and details.
#' @keywords package
#' @importFrom utils packageName
#' @importFrom grDevices xy.coords
#' @useDynLib bnxFortran, .registration = TRUE
#' @exportPattern "^[[:alpha:]]+"
NULL

#>----------------------------------------------------------------------------<#


#>-arguments------------------------------------------------------------------<#

#' Documentation of Recurring Package Arguments
#' @name argCallby
#' @param callby A single character scalar defining the interface to the
#'   exported function. This must be one of \code{"C"} indicates the \code{.C}
#'   foreign function interface, \code{"Fortran"} indicates the \code{.Fortran}
#'   foreign function interface, or \code{"Call"} indicates the \code{.Call}
#'   modern C/C++ function interface. The supported \code{callby} choices depend
#'   on the individual function. Any unambiguous substring can be given.
#' @keywords internal
NULL

#>----------------------------------------------------------------------------<#
