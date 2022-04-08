#' Matlab object names
#'
#' \code{get_names()} can read Matlab files
#'
#' @param file  A path to a file. Files ending with `.mat`.
#'
#' @return A vector or array with up to 3 dimensions.
#' @export
get_names <- function(file) {
  get_names_(file)
}
