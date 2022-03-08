
<!-- README.md is generated from README.Rmd. Please edit that file -->

# readmat

<!-- badges: start -->
<!-- badges: end -->

Readmat requires a full license and installation of Matlab^{(R)} if you
don’t have this then the `R.matlab` package is much more suitable. The
only goal of this package is to provide a potentially faster approach,
especially when dealing with large matrices.

This package is definitely under development!

## Benchmark

``` r
library(R.matlab)
#> R.matlab v3.6.2 (2018-09-26) successfully loaded. See ?R.matlab for help.
#> 
#> Attaching package: 'R.matlab'
#> The following objects are masked from 'package:base':
#> 
#>     getOption, isOpen
library(readmat)
```

## Installation

You can install the development version of readmat from
[GitHub](https://github.com/) with:

``` r
# install.packages("devtools")
devtools::install_github("MartinSchobben/readmat")
```
