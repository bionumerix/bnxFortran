# bnxFortran <img src="man/figures/logo.png" align="right" />

[![Project Status: Active – The project has reached a stable, usable state and is being actively developed.](http://www.repostatus.org/badges/latest/active.svg)](http://www.repostatus.org/#active)
[![GPL-3](https://img.shields.io/badge/license-GPL--3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0.en.html)
[![Travis Build Status](https://travis-ci.org/bionumerix/bnxFortran.svg?branch=master)](https://travis-ci.org/bionumerix/bnxFortran)
[![AppVeyor Build Status](https://ci.appveyor.com/api/projects/status/github/bionumerix/bnxFortran?branch=master&svg=true)](https://ci.appveyor.com/project/bionumerix/bnxFortran)
[![Coverage Status](https://codecov.io/github/bionumerix/bnxFortran/branch/master/graph/badge.svg)](https://codecov.io/github/bionumerix/bnxFortran?branch=master)
[![CRAN Status Badge](http://www.r-pkg.org/badges/version/bnxFortran)](https://cran.r-project.org/package=bnxFortran)

## Overview

The 'bnxFortran' package provides some C functions that wrap Fortran algorithms.
These interface functions are implemented here to be called directly from the
C or C++ source code level of other R packages.

### Background

This package has been created with at least two main purposes in mind:

A) Using R's `R_RegisterCCallable` to enable function calling at the the source
  code (`src`) level of other R packages.
B) Placing all *Fortran* algorithms needed by the *BioNumeriX (BNX)* R packages
  and associated C/C++ wrapper functions at a central place for maintenance and
  reusability.
C) ... (etc.).

### Status

Currently, the following *Fortran* algorithms are wrapped and can be called from
C/C++ source code within other packages (`src`) source code:

- `nnls`: the Lawson-Hanson NNLS implemention of non-negative least squares
  written by CL Lawson & RJ Hanson (1995) with modifications by KM Mullen & IHM
  van Stokkum
  (CRAN [nnls](https://cran.r-project.org/web/packages/nnls/index.html)).
- `akima` algorithms ACM 433 and 697: the "original" (ACM 433, Akima 1970) or
  "improved" method (ACM 697, Akima 1991) after H Akima originally ported to R
  by A Gebhardt *et. al.*
  (CRAN [akima](https://cran.r-project.org/web/packages/akima/index.html)).

Possible improvements, additions as well as next steps are listed in the
[TODO.md](TODO.md) file.

## Install

Stable releases of this package are usually made available at and can be
installed from [CRAN](https://cran.r-project.org) using R via the standard

``` r
# The most-likely easiest way to get this package installed:
install.packages("bnxFortran")
```

### Development version

To get a bug fix, or use a feature from the latest development version, you can
install this package from GitHub using:

``` r
## Installation from source gets you the latest (developmental) fixes:
# You may need to pre-install all necessary dependencies (if any is missing).
# You may need to set `httr::set_config(httr::config(ssl_verifypeer = 0L))`.
if (!require("devtools"))
  install.packages("devtools")
devtools::install_github("bionumerix/bnxFortran")
```

Alternatively, you can install the release of the latest development version
from the *BioNumeriX (BNX)* R repository (under development) via:

``` r
## Currently under development:
install.packages("bnxFortran", repos = "http://bionumerix.github.io/uran")
```

## Cheatsheet

Under development.

## Usage

Under development. See the documentation and vignettes (if any).

## Citation

When using this R-package for your work or research purposes, please cite this
package appropriately. Use the following R command to get the recent suggested
citation information in publications.

``` r
citation("bnxFortran")
```

## License

This package as a whole is distributed under GPL-3 (GNU GENERAL PUBLIC LICENSE
version 3). Other license terms may apply for third party algorithms. Read the
[license](./LICENSE) file to see for license details.

This package may include other open source functions, software and components.
These are listed including copies of their license agreements within the
[license](./LICENSE) file.

Third party copyrights are property of their respective owners.

## Support

Regarding bug reports, please open an issue at the respective repository issue
site at [.../issues/new](https://github.com/bionumerix/bnxFortran/issues/new).
Please include an example that can be used to reproduce the error or bug. The
easier a potential bug can be reproduced, the faster a solution will be in
place. Please check out the [project issue template](.github/ISSUE_TEMPLATE.md)
for further details.

In case of questions, missing functions, todo's etc. please open an issue
with appropriate / respective label at the above-mentioned issue page.

Please read carefully the [contributing](.github/CONTRIBUTING.md) and
[code of conduct](.github/CODE_OF_CONDUCT.md) guidelines.

## Further reading

Please read the [contributing](.github/CONTRIBUTIING.md) guidelines if you are
interested in contributing to this project.

Please read also the [code of conduct](.github/CODE_OF_CONDUCT.md) remarks as a
set of rules outlining the social norms, rules and responsibilities of, or
proper practices for, an individual, party or organization when contributing to
this project.

## Remarks

This R package includes functions derived from other external sources, such as
other R packages. The authors of the functions or packages are listed here as
contributors (maybe incomplete). For details and complete list lookup the
[license](./LICENSE) file and the source code of this package too.

- Dirk Steinhauser

with contributions by:

- Hiroshi Akima, Albrecht Gebhardt, Thomas Petzold, Martin Maechler
- Katharine M. Mullen, Ivo H. M. van Stokkum, Charles L. Lawson, Richard J.
  Hanson
- R Development Core Team / R Foundation

-----

Please note that this project is released with a [Contributor Code of
Conduct](.github/CODE_OF_CONDUCT.md). By participating in this project
you agree to abide by its terms.
