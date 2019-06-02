# Contribution Guidelines

## General

We welcome contributions from everybody, including bug and issue fixes, new
feature implementations as well as documentation and example improvements.

Please find below some advices and suggestions:

* It is strongly suggested to discuss changes and contributions using a Github
  [issue][ISSUE], in particular when these issues and / or suggested changes are
  substantial.

* Prior opening a new issue, please visit the current issues to see if a
  similar issue may already exists and, in the latter case, please join
  efforts.

* Before sending a pull request, it is highly recommended to first discuss
  possible changes using a Github issue, especially if the changes are likely
  substantial.

* When contributing code check the license terms.

* Make code contribution changes as small and contained as possible ideally
  always under different Github commits, if feasible, to simplify code review.

* Ideally, always add examples in the example section and unit test checks
  within the `testthat` of this package.

* Always avoid platform specific code to assure that this package builds and
  checks under Windows, Linux and OSX. Pull requests will also be checked by
  via <https://travis-ci.org/>, <https://ci.appveyor.com/> and maybe more.

* Please follow the coding style used in the package. See below for further
  details.

* Update the documentation, i.e. the man pages and/or vignette etc., to make
  your changes easily visible to package users. You may use e.g `roxygen2` from
  within R for this.

* In case of changes visible to the users additions to the `NEWS` and
  `ChangeLog` file are highly appreciated.

## Reporting an Issue

If you find a (potential) bug within this package, it is strongly recommended to
[file an issue][ISSUE]. Please provide as much relevant information as you can.
Also, please include a minimal [reproducible example](http://www.sscce.org/)
(if possible) as otherwise tracing and fixing the issue will be either difficult
or even unlikely.

Please also supply the session information output (from R's `sessionInfo()`)
when reporting an issue.

## Copyright

This package is released under the [GPL-3](http://www.gnu.org/licenses/gpl.html)
(or later). Thus, your contribution must be either under this or a compatible
license! For simplification, we prefer contributions under the GPL (>= 3)
license terms and generally assume this license unless explicitly stated.

## Coding Styles

Please follow the coding style used in the package. See below for further
details. Updated and more detailed coding style version may follow below in
future versions.

### R coding style

See also the Bioconductor
[coding style](https://bioconductor.org/developers/how-to/coding-style/).

### C / C++ coding style

Please follow the `K&R` code styling principle as e.g. implemented in
[Eclipse](https://www.eclipse.org/) IDE for C/C++ Developers.

## Code of Conduct

Please note that this project is released with a [Contributor Code of
Conduct](CODE_OF_CONDUCT.md). By participating in this project you agree to
abide by its terms.

[ISSUE]: https://github.com/bionumerix/bnxFortran/issues
