#' @export
read_mat <- function(file, type = "double") {
  nm <- fs::path_file(file) |> fs::path_ext_remove()
  if (type == "double") {
    rm <- read_mat_dbl(file)
  } else if (type == "integer") {
    rm <- read_mat_int(file)
  }
  attr(rm, "file") <- nm
  rm
}
