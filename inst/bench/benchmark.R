bm <- bench::mark(
  r = {
    R.matlab::readMat(readmat::get_matlab("double-large-cube.mat"))$big
  },
  cpp = {
    readmat::read_mat(readmat::get_matlab("double-large-cube.mat")[[1]])
  },
  min_iterations = 10,
  max_iterations = 25,
  relative = TRUE,
  check = FALSE
)
# removed list column
bm <- dplyr::select(bm, -tidyselect::vars_select_helpers$where(is.list)) |>
  dplyr::mutate(package = c("R.matlab", "readmat"), .before = "min")

usethis::use_data(bm, overwrite = TRUE, internal = TRUE)
