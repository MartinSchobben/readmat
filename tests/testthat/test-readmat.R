test_that("readmat can convert different types and structures", {

  # not matlab installed
  skip_on_cran()
  skip_on_ci()

  expect_snapshot(
    read_mat(get_matlab("uint16-vec.mat"))
  )
  expect_snapshot(
    read_mat(get_matlab("uint16-mat.mat"))
  )
  expect_snapshot(
    read_mat(get_matlab("uint16-cube.mat"))
  )
  expect_snapshot(
    read_mat(get_matlab("int16-vec.mat"))
  )
  expect_snapshot(
    read_mat(get_matlab("int16-mat.mat"))
  )
  expect_snapshot(
    read_mat(get_matlab("int16-cube.mat"))
  )
  expect_snapshot(
    read_mat(get_matlab("double-vec.mat"))
  )
  expect_snapshot(
    read_mat(get_matlab("double-mat.mat"))
  )
  expect_snapshot(
    read_mat(get_matlab("double-cube.mat"))
  )
  expect_snapshot(
    read_mat(get_matlab("double-large-cube.mat"))
  )
  expect_snapshot(
    read_mat(get_matlab("multi-object.mat"))
  )
})

test_that("error with no matlab installation", {

  expect_error(
    read_mat(get_matlab("uint16-vec.mat")),
    "A full installation of Matlab is required."
  )
})
