AC_INIT([readmat],[0.0.0.9000])

# Find the compiler and compiler flags used by R.
: ${R_HOME=`R RHOME`}
if test -z "${R_HOME}"; then
echo "could not determine R_HOME"
exit 1
fi
CXX=`"${R_HOME}/bin/R" CMD config CXX`
CXXFLAGS=`"${R_HOME}/bin/R" CMD config CXXFLAGS`
CPPFLAGS=`"${R_HOME}/bin/R" CMD config CPPFLAGS`
AC_LANG(C++)
AC_PROG_CPP

# Search for a system library mat.
# Search for mat headers.
have_libmat=no
LIBMAT_CPPFLAGS=""
LIBMAT_LIBS="-lmat"

PKG_PROG_PKG_CONFIG

if test [ -n "$PKG_CONFIG" ] ; then
  AC_MSG_CHECKING([pkg-config for libmat])
  if $PKG_CONFIG --exists libmat; then
    have_libmat=yes
    LIBMAT_CPPFLAGS=`"${PKG_CONFIG}" --cflags mat.h`
    LIBMAT_LIBS=`"${PKG_CONFIG}" --libs mat`
  fi
  AC_MSG_RESULT([${have_libmat}])
fi

if test "x${have_libmat}" = xno; then
  AC_CHECK_HEADERS(mat.h, MATLAB/R2021b/extern/include, [have_libmat=yes], [AC_ERROR([A full installation of Matlab is required.])])
fi

# Write the flags into the src/Makevars file.
AC_SUBST([PKG_CPPFLAGS], ["${PKG_CPPFLAGS}"])
AC_SUBST([PKG_LIBS], ["${LIBS} ${PKG_LIBS} ${LIBMAT_LIBS}"])
AC_CONFIG_FILES([src/Makevars])
AC_OUTPUT

echo "
  --------------------------------------------------
  Configuration for ${PACKAGE_NAME} ${PACKAGE_VERSION}

    libs:     ${PKG_LIBS}

  --------------------------------------------------
"
