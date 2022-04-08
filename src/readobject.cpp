#include "readobject.hpp"

cpp11::doubles read_object(MATFile *pmat, char *object) {

    // extract the specified variable
    mxArray *arr = matGetVariable(pmat, object);

    if (arr != NULL && mxIsDouble(arr) && !mxIsEmpty(arr)) {

      // pointer to he first element of the real data (NULL is no data)
      double *pr = mxGetPr(arr);
      const char *type;
      type = mxGetClassName(arr); // data type
      mwSize num = mxGetNumberOfElements(arr); // max number of elements
      mwSize ndims = mxGetNumberOfDimensions(arr); // number of dimensions
      const mwSize *dims = mxGetDimensions(arr);

      int M = dims[0];
      int N = dims[1];
      int L = dims[2];

      // print some info about the object
      std::cout << "Object has " << ndims << " dimensions of";
      std::cout << " size: " << M ;
      if (N != 0) std::cout << ", " << N ;
      if (L != 0) std::cout << ", " << L ;
      std::cout << " and with type: " << type << std::endl;

      if (pr != NULL) {

        // get the object
        std::vector<double> v;
        v.reserve(num);
        v.assign(pr, pr + num);

        // Set the number of rows and columns to attribute dim of the vector object.
        cpp11::writable::doubles u = v;

        if (M > 1 & L == 0) {
          u.attr("dim") = {M, N}; // matrix
        } else if (M > 1 & L != 0) {
          u.attr("dim") = {M, N, L}; // cube
        }

        return u;

      } else {
        cpp11::stop("This is not a valid pointer to an array element.") ;
      }
    } else {
      cpp11::stop("The array is either empty or not of type double.") ;
    }

    // cleanup
    mxDestroyArray(arr);

}
