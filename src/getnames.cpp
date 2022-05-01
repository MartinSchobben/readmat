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

  /*
   * get directory of MAT-file
   */
  const char **dir{};
  const char *name{};
  mxClassID  category{};

  int	ndir{};
  dir = (const char **)matGetDir(pmat, &ndir); // C style cast. you should convert this to a static_cast

  // list for storage
  cpp11::writable::strings out(numvars);

  for (int i{0}; i < ndir; i++) {

    Rprintf("Name of object is %s.\n", dir[i]);
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
