#' @export
read_mat <- function(file) {
  # file name
  nm <- fs::path_file(file) |> fs::path_ext_remove()
  # file
  rm <- read_mat_(file)
  # add file name as attribute
  attr(rm, "file") <- nm
  rm
}
