#include "readmat.hpp"

[[cpp11::register]]
cpp11::strings get_names_(const char* file) {

#if HAVE_MAT_H

  // inspired by extern/examples/eng_mat/matdgns.c file of matlab

  // open mat-file
  MATFile *pmat = matOpen(file, "r");
  if (pmat == NULL)
    cpp11::stop("No file could be found.");

  int numvars{0};
  char **varlist = matGetDir(pmat, &numvars);

  Rprintf("There are %.1i objects in this MAT file. \n", numvars);

  /*
   * get directory of MAT-file
   */
  const char **dir{};
  const char *name{};
  mxClassID  category{};

  int	ndir{};
  dir = (const char **)matGetDir(pmat, &ndir);

  // list for storage
  cpp11::writable::strings out(numvars);

  for (int i{0}; i < ndir; i++) {

    Rprintf("The name of the object is %s.\n", dir[i]);
    std::string u{};
    u = static_cast<std::string>(dir[i]);
    out[i] = u;

  }

  return out;

  // clean-up
  mxFree(dir);

#else
  cpp11::stop("A full installation of Matlab is required.");
#endif
}
