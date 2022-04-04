#include <cpp11.hpp>
#include <iostream>
#include "mat.h"
#include <vector>

[[cpp11::register]]
void get_mat_names_(const char* file) {

  // inspired by extern/examples/eng_mat/matdgns.c file of matlab

  // open mat-file
  MATFile *pmat = matOpen(file, "r");
  // if (pmat == NULL) return 0;

  int numvars{0};
  char **varlist = matGetDir(pmat, &numvars);

  std::cout << "There are " << numvars << " objects in this MAT file. \n";

  /*
   * get directory of MAT-file
   */
  const char **dir{};
  int	ndir{};
  dir = (const char **)matGetDir(pmat, &ndir);


  for (int i{0}; i < ndir; i++) {
      std::cout << "Ther names of the objects are " << dir[i] << "\n";
  }

  // clean-up
  mxFree(dir);

}
