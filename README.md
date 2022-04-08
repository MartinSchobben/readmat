
<!-- README.md is generated from README.Rmd. Please edit that file -->

# readmat

<!-- badges: start -->
<!-- badges: end -->

Readmat requires a full license and installation of Matlab<sup>(R)</sup>
if you don’t have this then the `R.matlab` package is much more
suitable. The only goal of this package is to provide a potentially
faster approach, especially when dealing with large matrices.

This package is definitely under development!

## Benchmark

A data cube of 400 x 400 x 400 values.

``` r
readmat::read_mat(readmat::get_matlab("double-large-cube.mat"))[[1]] |> 
  dim()
#> [1] 400 400 400
```

Comparing `R.matlab` and `readmat`.

| package  |  min | median | itr/sec | mem_alloc | n_itr | n_gc | total_time |
|:---------|-----:|-------:|--------:|----------:|------:|-----:|-----------:|
| R.matlab | 3.31 |   3.36 |    1.00 |      3.98 |    10 |    0 |  27.775926 |
| readmat  | 1.00 |   1.00 |    3.33 |      1.00 |     5 |    5 |   4.173084 |

## Installation

You can install the development version of readmat from
[GitHub](https://github.com/) with:

``` r
# install.packages("devtools")
devtools::install_github("MartinSchobben/readmat")
```
