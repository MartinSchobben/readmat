#include "readmat.hpp"


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
  Rprintf("%.1i object(s) found in this MAT file. \n", numvars);

  cpp11::writable::list out(numvars);

  // get the different objects in the file
  for(int i{0}; i < numvars; ++i) {

    // extract the specified variable
    mxArray *arr = matGetVariable(pmat, varlist[i]);

    if (arr == NULL  && mxIsEmpty(arr)) {
      cpp11::stop("The array is probably empty.");
    }

    // object header
    create_header(arr);

    // determine type and get object https://nl.mathworks.com/help/matlab/matlab_external/matlab-to-c-data-type-mapping.html
    if (mxIsDouble(arr)) {

      // object
      cpp11::writable::doubles u({0});
      std::vector<double> v{};
      create_object<double>(arr, v);

      // Set the number of rows and columns to attribute dim of the vector object.
      u = v;
      create_dimensions(arr, u);

      // assign to list
      out[i] = u;

    } else if (mxIsInt8(arr)) {

      // object
      cpp11::writable::integers u({0});
      std::vector<int8_t> v{};
      create_object(arr, v);

      // Set the number of rows and columns to attribute dim of the vector object.
      u = v;
      create_dimensions(arr, u);

      // assign to list
      out[i] = u;

    } else if (mxIsInt16(arr)) {

      // object
      cpp11::writable::integers u({0});
      std::vector<int16_t> v{};
      create_object(arr, v);

      // Set the number of rows and columns to attribute dim of the vector object.
      u = v;
      create_dimensions(arr, u);

      // assign to list
      out[i] = u;

    } else if (mxIsInt32(arr)) {

      // object
      cpp11::writable::integers u({0});
      std::vector<int32_t> v{};
      create_object(arr, v);

      // Set the number of rows and columns to attribute dim of the vector object.
      u = v;
      create_dimensions(arr, u);

      // assign to list
      out[i] = u;

    } else if (mxIsInt64(arr)) {

      // object
      cpp11::writable::integers u({0});
      std::vector<int64_t> v{};
      create_object(arr, v);

      // Set the number of rows and columns to attribute dim of the vector object.
      u = v;
      create_dimensions(arr, u);

      // assign to list
      out[i] = u;

    } else if (mxIsUint8(arr)) {

      // object
      cpp11::writable::doubles u({0});
      std::vector<uint8_t> v{};
      create_object(arr, v);

      // Set the number of rows and columns to attribute dim of the vector object.
      // also cast into signed integers as R does not have these

      u = v;
      create_dimensions(arr, u);

      // assign to list
      out[i] = u;

    } else if (mxIsUint16(arr)) {

      // object
      cpp11::writable::doubles u({0});
      std::vector<uint16_t> v{};
      create_object(arr, v);

      // Set the number of rows and columns to attribute dim of the vector object.
      // also cast into signed integers as R does not have these

      u = v;
      create_dimensions(arr, u);

      // assign to list
      out[i] = u;

    } else if (mxIsUint32(arr)) {

      // object
      cpp11::writable::doubles u({0});
      std::vector<uint32_t> v{};
      create_object(arr, v);

      // Set the number of rows and columns to attribute dim of the vector object.
      // also cast into signed integers as R does not have these

      u = v;
      create_dimensions(arr, u);

      // assign to list
      out[i] = u;

    } else if (mxIsUint64(arr)) {

      // object
      cpp11::writable::doubles u({0});
      std::vector<uint64_t> v{};
      create_object(arr, v);

      // Set the number of rows and columns to attribute dim of the vector object.
      // also cast into signed integers as R does not have these

      u = v;
      create_dimensions(arr, u);

      // assign to list
      out[i] = u;

    } else {

      cpp11::stop("Unkown data type.");

    }


    // cleanup
    mxDestroyArray(arr);

  }

  return out;

  // clean-up
  mxFree(varlist);
  // close file
  matClose(pmat);

}



