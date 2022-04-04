// Generated by cpp11: do not edit by hand
// clang-format off


#include "cpp11/declarations.hpp"
#include <R_ext/Visibility.h>

// get-matlab-names.cpp
void get_mat_names_(const char* file);
extern "C" SEXP _readmat_get_mat_names_(SEXP file) {
  BEGIN_CPP11
    get_mat_names_(cpp11::as_cpp<cpp11::decay_t<const char*>>(file));
    return R_NilValue;
  END_CPP11
}
// read-matlab-dbl.cpp
cpp11::doubles read_mat_dbl(const char* file);
extern "C" SEXP _readmat_read_mat_dbl(SEXP file) {
  BEGIN_CPP11
    return cpp11::as_sexp(read_mat_dbl(cpp11::as_cpp<cpp11::decay_t<const char*>>(file)));
  END_CPP11
}
// read-matlab-int.cpp
cpp11::doubles read_mat_int(const char* file);
extern "C" SEXP _readmat_read_mat_int(SEXP file) {
  BEGIN_CPP11
    return cpp11::as_sexp(read_mat_int(cpp11::as_cpp<cpp11::decay_t<const char*>>(file)));
  END_CPP11
}

extern "C" {
static const R_CallMethodDef CallEntries[] = {
    {"_readmat_get_mat_names_", (DL_FUNC) &_readmat_get_mat_names_, 1},
    {"_readmat_read_mat_dbl",   (DL_FUNC) &_readmat_read_mat_dbl,   1},
    {"_readmat_read_mat_int",   (DL_FUNC) &_readmat_read_mat_int,   1},
    {NULL, NULL, 0}
};
}

extern "C" attribute_visible void R_init_readmat(DllInfo* dll){
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE);
}
