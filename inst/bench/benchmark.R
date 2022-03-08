bm <- bench::mark(
  r = {
    R.matlab::readMat(readmat::get_matlab("num-large-cube.mat"))$big
  },
  cpp = {
    readmat::read_mat(readmat::get_matlab("num-large-cube.mat"))
  },
  max_iterations = 10,
  check = TRUE,
  relative = TRUE
) |> tidyr::drop_na()

saveRDS(bm)
