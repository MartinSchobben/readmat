
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

A data cub of 400, 400, 400.

``` r
# powered by bench::mark()
knitr::kable(readmat:::bm)
```

|      min |  median |  itr/sec | mem_alloc | gc/sec | n_itr | n_gc | total_time |
|---------:|--------:|---------:|----------:|-------:|------:|-----:|-----------:|
| 3.071944 | 3.23496 | 1.000000 |   3.98151 |    NaN |    10 |    0 |  26.659742 |
| 1.000000 | 1.00000 | 3.215313 |   1.00000 |    Inf |     5 |    5 |   4.145746 |



    ## Installation

    You can install the development version of readmat from [GitHub](https://github.com/) with:

    ``` r
    # install.packages("devtools")
    devtools::install_github("MartinSchobben/readmat")
