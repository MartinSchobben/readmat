bm <- bench::mark(
  r = {
    R.matlab::readMat(readmat::get_matlab("num-large-cube.mat"))$big
  },
  cpp = {
    readmat::read_mat(readmat::get_matlab("num-large-cube.mat"))
  },
  min_iterations = 10,
  max_iterations = 25,
  relative = TRUE
)
# removed list column
bm <- dplyr::select(bm, -tidyselect::vars_select_helpers$where(is.list))

usethis::use_data(bm, overwrite = TRUE, internal = TRUE)
