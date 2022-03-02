.onUnload <- function (libpath) {
  library.dynam.unload("readmat", libpath)
}
