AC_PREREQ([2.69])
AC_INIT([number], [1.0], [], [])
AM_INIT_AUTOMAKE([foreign])
DX_INIT_DOXYGEN([number])
AC_CONFIG_SRCDIR([src/number.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PATH_PROG([HELP2MAN], [help2man])

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([libintl.h locale.h stdlib.h])

# Checks for library functions.
AC_CHECK_FUNCS([setlocale])

AC_CONFIG_FILES([Makefile src/Makefile po/Makefile Doxyfile src/number.md])
AC_OUTPUT
