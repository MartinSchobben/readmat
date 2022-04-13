AC_INIT([readmat],[0.0.0.9000])

# Find the compiler and compiler flags used by R.
: ${R_HOME=`R RHOME`}
if test -z "${R_HOME}"; then
  echo "could not determine R_HOME"
  exit 1
fi
CXX=`"${R_HOME}/bin/R" CMD config CXX`
CXXFLAGS=`"${R_HOME}/bin/R" CMD config CXXFLAGS`
# set original preprocessor flags
R_CPPFLAGS=`"${R_HOME}/bin/R" CMD config CPPFLAGS`

# check c++
AC_LANG(C++)
AC_PROG_CPP

# check for matlab installation
AC_CHECK_PROG([matlab],[matlab],[yes],[no])
AM_CONDITIONAL([FOUND_MATLAB], [test "x$matlab" = xyes])
AM_COND_IF([FOUND_MATLAB],,[AC_MSG_ERROR([A full Matlab installation is required.])])

# matlab root
MAT_ROOT=$(matlab -batch 'disp(matlabroot)')
# matlab shared libraries
MAT_LIBS=$(matlab -batch "disp(fullfile(matlabroot, 'bin', computer('arch')))")

# Rpath
RPATH="-Wl,-rpath,${MAT_LIBS}"

# the search path of a default Matlab install (tricking AS_SEARCH_*)
MAT_CPPFLAGS="-I${MAT_ROOT}/extern/include"
CPPFLAGS="${MAT_CPPFLAGS} ${R_CPPFLAGS}"
LDFLAGS="-L${MAT_LIBS} ${RPATH}"

# check for libraries
have_mat=no

AC_SEARCH_LIBS([matOpen], [mat], [have_mat=yes])

if test "x${have_mat}" = xyes; then
  AC_CHECK_HEADERS([mat.h], [], [have_mat=yes])
fi

if test "x${have_mat}" = xno; then
  AC_MSG_ERROR([
  ------------------------------------------------------------------------
  A full installation of Matlab is required.

  If you believe Matlab is installed on your system but this script is
  simply unable to find it, you can specify the include and lib paths
  manually:

  R CMD INSTALL ${PACKAGE_NAME} \\
     --configure-vars='LIBS=-L/path/to/libs CPPFLAGS=-I/path/to/headers'
  ------------------------------------------------------------------------])
fi

# Write the flags into the src/Makevars file.
AC_SUBST([PKG_CPPFLAGS], ["${CPPFLAGS}"])
AC_SUBST([PKG_LIBS], ["-L${MAT_LIBS} ${ac_cv_search_matOpen} ${RPATH}"])
AC_CONFIG_FILES([src/Makevars])
AC_OUTPUT

# print something nice
echo "
  -----------------------------------------------------------
  Configuration for ${PACKAGE_NAME} ${PACKAGE_VERSION}

    cppflags: ${PKG_CPPFLAGS}
    libs:     ${PKG_LIBS}

  -----------------------------------------------------------
"
