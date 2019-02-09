# nocov start

#>----------------------------------------------------------------------------<#

## no S4 methodology here; speedup:
.noGenerics <- TRUE

#>----------------------------------------------------------------------------<#


#>----------------------------------------------------------------------------<#

##' @keywords internal
.onLoad <- function(libname, pkgname) {
    tryCatch(
        library.dynam("bnxFortran", pkgname, libname),
        error = function(e) e
    )
}
##' @keywords internal
.onAttach <- function(libname, pkgname) {
    .onLoad(libname, pkgname)
}

##' @keywords internal
.onUnload <- function(libpath) {
    library.dynam.unload("bnxFortran", libpath)
}
##' @keywords internal
.onDetach <- function(libpath) {
    .onUnload(libpath)
}

#>----------------------------------------------------------------------------<#

# nocov end
