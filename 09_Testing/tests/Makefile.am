TESTS_ENVIRONMENT = CK_VERBOSITY=$(CK_VERBOSITY)
TESTS = test_init test_null test_grow test_pop test_push
check_PROGRAMS = test_init test_null test_grow test_pop test_push

AM_CFLAGS = -I$(top_builddir)/src @CHECK_CFLAGS@
LDADD = $(top_builddir)/src/libbuf.la @CHECK_LIBS@

