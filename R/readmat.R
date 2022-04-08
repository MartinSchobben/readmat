#' @title Read a Matlab file
#'
#'
#' \code{read_mat()} can read Matlab files
#'
#' @param file  A path to a file. Files ending with `.mat`.
#'
#' @return A vector or array with up to 3 dimensions.
#'
#' @export
#' @examples
#' # Use \code{get_matlab()} to access the examples bundled with this package
#'
#' # Read Matlab file with one object
#' read_mat(get_matlab("double-vec.mat"))
#'
#' # Read Matlab file with multiple objects
#' read_mat(get_matlab("multi-object.mat"))
#'
read_mat <- function(file) {
  # file name
  nm <- fs::path_file(file) |> fs::path_ext_remove()
  # file
  rm <- read_mat_(file)
  # add file name as attribute
  attr(rm, "file") <- nm
  rm
}
