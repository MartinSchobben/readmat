#include "readobject.hpp"


[[cpp11::register]]
cpp11::list read_mat_(const char* file) {

  // inspired by https://stackoverflow.com/questions/26234673/matlab-api-reading-mat-file-from-c-using-stl-container
  // open mat-file
  MATFile *pmat = matOpen(file, "r");
  if (pmat == NULL)
    cpp11::stop("No file could be found.");

  // how many objects in file (https://github.com/hokiedsp/libmatpy/blob/master/test/test_libmat.cpp)
  int numvars{0};
  char **varlist = matGetDir(pmat, &numvars);

  // print some info about the file
  std::cout << numvars << " object(s) found in this MAT file." << std::endl;

  cpp11::writable::list out(numvars);


  // get the different objects in the file
  for(int i{0}; i < numvars; ++i) {

   out[i] = read_object(pmat, varlist[i]);

  }

  return out;

  // clean-up
  mxFree(varlist);
  // close file
  matClose(pmat);

}



