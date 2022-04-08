#include "readmat.hpp"

void create_header(mxArray *arr) {

    const char *type  = mxGetClassName(arr); // data type
    mwSize ndims = mxGetNumberOfDimensions(arr); // number of dimensions
    const mwSize *dims = mxGetDimensions(arr); // dimension sizes

    // print some info about the object
    Rprintf("Object has %.0i dimensions of", ndims);
    Rprintf(" size: %.0i", dims[0]);
    for (int i{1}; i < ndims; ++i) {
      Rprintf(", %.0i", dims[i]) ;
    }
    Rprintf(", with type: %s. \n", type);

}


