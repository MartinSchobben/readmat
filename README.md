
<!-- README.md is generated from README.Rmd. Please edit that file -->

# readmat

<!-- badges: start -->

[![R-CMD-check](https://github.com/MartinSchobben/readmat/workflows/R-CMD-check/badge.svg)](https://github.com/MartinSchobben/readmat/actions)
[![Project Status: Concept – Minimal or no implementation has been done
yet, or the repository is only intended to be a limited example, demo,
or
proof-of-concept.](https://www.repostatus.org/badges/latest/concept.svg)](https://www.repostatus.org/#concept)
[![license](https://img.shields.io/github/license/mashape/apistatus.svg)](https://choosealicense.com/licenses/mit/)
[![Last-changedate](https://img.shields.io/badge/last%20change-2022--04--14-yellowgreen.svg)](/commits/master)
<!-- badges: end -->

Readmat requires a full license and installation of Matlab<sup>(R)</sup>
if you don’t have this then the `R.matlab` (Bengtsson 2018) package is
much more suitable. The only goal of this package is to provide a
potentially faster approach, especially when dealing with large
matrices.

This package is definitely under development!

## Benchmark

A data cube of 400 x 400 x 400 values.

``` r
readmat::read_mat(readmat::get_matlab("double-large-cube.mat"))[[1]] |> 
  dim()
#> 1 object(s) found in this MAT file. 
#> Object has 3 dimensions of size: 400, 400, 400, with type: double.
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

## Credits

The construction of the R (R Core Team 2022) package `readmat` and
associated documentation was aided by the packages; `devtools` (Wickham
et al. 2021) and `cpp11` (Hester and François 2021).

# References

<div id="refs" class="references csl-bib-body hanging-indent">

<div id="ref-R.matlab" class="csl-entry">

Bengtsson, Henrik. 2018. *R.matlab: Read and Write MAT Files and Call
MATLAB from Within r*. <https://github.com/HenrikBengtsson/R.matlab>.

</div>

<div id="ref-cpp11" class="csl-entry">

Hester, Jim, and Romain François. 2021. *Cpp11: A c++11 Interface for
r’s c Interface*. <https://CRAN.R-project.org/package=cpp11>.

</div>

<div id="ref-rversion" class="csl-entry">

R Core Team. 2022. *R: A Language and Environment for Statistical
Computing*. Vienna, Austria: R Foundation for Statistical Computing.
<https://www.R-project.org/>.

</div>

<div id="ref-devtools" class="csl-entry">

Wickham, Hadley, Jim Hester, Winston Chang, and Jennifer Bryan. 2021.
*Devtools: Tools to Make Developing r Packages Easier*.
<https://CRAN.R-project.org/package=devtools>.

</div>

</div>
