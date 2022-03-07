#' Get path to matlab file
#'
#' This function is modified from the package `readr` to access
#' the bundled datasets in directory `inst/extdata` of `pointapply`. This
#' function make them easy to access. This function is modified from
#' \code{\link[readr:readr_example]{readr_example}} of the package
#' \code{\link[readr]{readr}}.
#'
#' @param path Name of file. If `NULL`, the example files will be listed.
#' @export
get_matlab <- function(path = NULL) {
  if (is.null(path)) {
    dir(system.file("extdata", package = "readmat"))
  } else {
    system.file("extdata", path, package = "readmat", mustWork = TRUE)
  }
}
