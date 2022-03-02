#include <cpp11.hpp>
#include "mat.h"
#include <stdio.h>
#include <stdlib.h>
using namespace cpp11;

//' @export
[[cpp11::register]]
cpp11::doubles read_mat() {

  cpp11::doubles v {};
  const char* file {"num-vec.mat"};

  MATFile *pmat = matOpen(file, "r"); // "r" = read-only

  return v;
}
