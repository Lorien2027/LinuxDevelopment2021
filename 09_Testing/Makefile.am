SUBDIRS = src tests
gcov:	check
	$(MAKE) $(MAKEFLAGS) -C src gcov

GENERATES = src/libbuf.la src/libbuf.lo src/libbuf.c.gcov src/.deps src/.libs src/Makefile src/Makefile.in \
            tests/.deps tests/.libs tests/Makefile tests/Makefile.in \
            tests/*.trs tests/*.log tests/*.o \
            tests/test_grow tests/test_init tests/test_null tests/test_pop tests/test_push \
            config.* libtool ltmain.sh INSTALL COPYING stamp-h2 \
            *.in *.log *.o *~ .deps compile config.status configure depcomp install-sh \
            missing aclocal.m4 stamp-h1 Makefile Makefile.in test-driver autom4te.cache test.sh.trs
clean:
	rm -rf $(GENERATES)

