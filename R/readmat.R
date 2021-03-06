#' @title Read a Matlab file
#'
#'
#' \code{read_mat()} can read Matlab files
#'
#' @param file  A path to a file. Files ending with `.mat`.
#' @param names Include names of matlab objects (default = FALSE).
#'
#' @return A vector or array with up to 3 dimensions.
#'
#' @export
#' @examples
#' # Use \code{get_matlab()} to access the examples bundled with this package
#'
#' # Read Matlab file with one object
#' \dontrun{read_mat(get_matlab("double-vec.mat"))}
#'
#' # Read Matlab file with multiple objects
#' \dontrun{read_mat(get_matlab("multi-object.mat"))}
#'
read_mat <- function(file, names = FALSE) {
  # file name
  fl <- fs::path_file(file) |>
    fs::path_ext_remove()
  # file
  rm <- read_mat_(file)
  if (isTRUE(names)) {
    # set names of list
    nm <- get_names_(file)
    rm <- stats::setNames(rm ,nm)
  }
  # add file name as attribute
  attr(rm, "file") <- fl
  rm
}

