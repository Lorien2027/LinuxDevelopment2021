bin_PROGRAMS=number
number_SOURCES=number.c
AM_CFLAGS=-D'LOCALEDIR="$(localedir)"'

man1_MANS = number.1

%.1:	%
	-$(HELP2MAN) --no-info --output=$@ --name='@PACKAGE_NAME@' ./$<
