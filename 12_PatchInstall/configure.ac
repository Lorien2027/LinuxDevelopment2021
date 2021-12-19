AC_PREREQ([2.69])
AC_INIT([number], [1.0], [])
AM_INIT_AUTOMAKE([foreign])
AM_GNU_GETTEXT([external])
AM_GNU_GETTEXT_VERSION(0.19)
GETTEXT_PACKAGE=number
AC_SUBST(GETTEXT_PACKAGE)
ALL_LINGUAS="ru"
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

AC_CONFIG_FILES([Makefile src/Makefile po/Makefile.in])
AC_OUTPUT
