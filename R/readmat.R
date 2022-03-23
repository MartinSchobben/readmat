#' @export
read_mat <- function(file) {
  nm <- fs::path_file(file) |> fs::path_ext_remove()
  rm <- read_mat_(file)
  attr(rm, "file") <- nm
  rm
}
