CFLAGS = -Wall -O0 -g

bin_PROGRAMS=esub
esub_SOURCES=esub.c

TESTS=test.sh

GENERATES = esub INSTALL COPYING *.h *.in  *.log *.o *~ .deps compile config.status configure depcomp install-sh missing aclocal.m4 stamp-h1 Makefile test-driver autom4te.cache test.sh.trs
clean:
	rm -rf $(GENERATES)