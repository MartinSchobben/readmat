#ifndef READMAT_HPP
#define READMAT_HPP

#include <cpp11.hpp>
#include <iostream>
#include <vector>
#include "mat.h" // matlab

// function templates
template<typename T>
void create_object(mxArray *arr, std::vector<T> &v) {

  // pointer to he first element of the real data (NULL is no data)
  double *pr = mxGetPr(arr);
  mwSize num = mxGetNumberOfElements(arr); // max number of elements

  if (pr != NULL) {

    // get the object
    v.reserve(num);
    v.assign(pr, pr + num);

  } else {
    cpp11::stop("The array is probably empty.");
  }
}

template<typename T>
void create_dimensions(mxArray *arr, T &u) {

  // dimension sizes
  const mwSize *dims = mxGetDimensions(arr);
  // set attributes
  int M = dims[0];
  int N = dims[1];
  int L = dims[2];

  if (M > 1 & L == 0) {
    u.attr("dim") = {M, N}; // matrix
  } else if (M > 1 & L != 0) {
    u.attr("dim") = {M, N, L}; // cube
  }

}

// forward declarations
void create_header(mxArray *arr);
#endif
