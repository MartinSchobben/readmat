#include <cpp11.hpp>
#include <iostream>
#include "mat.h"
#include <vector>

[[cpp11::register]]
void get_mat_names_(const char* file) {

  // inspired by extern/examples/eng_mat/matdgns.c file of matlab

  // open mat-file
  MATFile *pmat = matOpen(file, "r");
  if (pmat == NULL)
    cpp11::stop("No file could be found.");

  int numvars{0};
  char **varlist = matGetDir(pmat, &numvars);

  std::cout << "There are " << numvars << " objects in this MAT file. \n";

  /*
   * get directory of MAT-file
   */
  const char **dir{};
  const char *name{};
  mxClassID  category{};

  int	ndir{};
  dir = (const char **)matGetDir(pmat, &ndir);


  for (int i{0}; i < ndir; i++) {

    std::cout << "The name of the object is " << dir[i] << "\n";
  }


  //
  // clean-up
  mxFree(dir);

}
