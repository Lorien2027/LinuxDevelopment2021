AC_PREREQ([2.69])
AC_INIT([Rhasher], [1.0], [])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_CONFIG_SRCDIR([rhasher.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AM_INIT_AUTOMAKE

# Checks for libraries.
AC_CHECK_HEADER([rhash.h], [], [AC_MSG_ERROR([Unable to find rhash.h])])
AC_CHECK_LIB([rhash], [rhash_msg], [], [AC_MSG_ERROR([Unable to find rhash])])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

AC_ARG_WITH([readline],
	[AS_HELP_STRING([--without-readline],
	[disable support for readline])],
	[],
	[with_readline=yes])

AS_IF([test "x$with_readline" != xno], [
 	AC_CHECK_HEADERS([readline/readline.h readline/history.h])
 	AC_CHECK_LIB([readline], [readline])])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
