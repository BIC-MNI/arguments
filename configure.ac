dnl Process this file with autoconf to produce a configure script.

AC_INIT
AC_CONFIG_SRCDIR([src/arguments.cpp])
AM_INIT_AUTOMAKE(arguments, 0.1)
AC_CONFIG_HEADER([config.h])


#------------------------------------------------------------------------
# Checks for compiler toolset.
#------------------------------------------------------------------------
AC_PROG_CC
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_MAKE_SET

AC_DISABLE_SHARED
AC_PROG_LIBTOOL


#------------------------------------------------------------------------
# Check that we have some required header files (and macros in them)
#------------------------------------------------------------------------
AC_HEADER_STDC
AC_CHECK_HEADERS(float.h limits.h malloc.h)


#------------------------------------------------------------------------
# Checks for typedefs, structures, and compiler characteristics.
#------------------------------------------------------------------------
AC_C_INLINE
AC_C_CONST
AC_TYPE_SIZE_T
#AC_CHECK_TYPE(bool,int)


#------------------------------------------------------------------------
# Checks for library functions.
#------------------------------------------------------------------------
AC_FUNC_VPRINTF
AC_CHECK_FUNCS(strtod strtol)


AC_OUTPUT([Makefile src/Makefile])




