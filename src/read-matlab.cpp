#include <cpp11.hpp>
#include <iostream>
#include "mat.h"
#include <vector>

[[cpp11::register]]
cpp11::doubles read_mat(const char* file) {

  // inspired by https://stackoverflow.com/questions/26234673/matlab-api-reading-mat-file-from-c-using-stl-container
  // open mat-file
  MATFile *pmat = matOpen(file, "r");
  if (pmat == NULL) return 0;

  // how many objects in file (https://github.com/hokiedsp/libmatpy/blob/master/test/test_libmat.cpp)
  int numvars{0};
  char **varlist = matGetDir(pmat, &numvars);

  std::cout << "There are " << numvars << " objects in this MAT file. \n";

  for(int i{0}; i < numvars; ++i) {

    // extract the specified variable
    mxArray *arr = matGetVariable(pmat, varlist[i]);

    if (arr != NULL && mxIsDouble(arr) && !mxIsEmpty(arr)) {

      // pointer to he first element of the real data (NULL is no data)
      double *pr = mxGetPr(arr);
      mwSize num = mxGetNumberOfElements(arr); // max number of elements
      mwSize ndims = mxGetNumberOfDimensions(arr); // number of dimensions
      const mwSize *dims = mxGetDimensions(arr);

      int M = dims[0];
      int N = dims[1];
      int L = dims[2];

      std::cout << "Object has " << ndims << " dimensions. These are the dimensions of the object " << M << "," << N << "," << L << ".\n";

      if (pr != NULL) {

        // get the object
        std::vector<double> v;
        v.reserve(num);
        v.assign(pr, pr+num);

        // Set the number of rows and columns to attribute dim of the vector object.
        cpp11::writable::doubles u = v;

        if (M > 1 & L == 0) {
          u.attr("dim") = {M, N}; // matrix
        } else if (M > 1 & L != 0) {
          u.attr("dim") = {M, N, L}; // cube
        }

        return u;
      }
    }

  // cleanup
    mxDestroyArray(arr);
    mxFree(varlist);
  }
  // close file
  matClose(pmat);
}



