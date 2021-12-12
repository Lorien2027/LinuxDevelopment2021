bin_PROGRAMS=number

pkgdata_DATA = number.1

%.1:	%
	-$(HELP2MAN) --no-info --output=$@ --name='@PACKAGE_NAME@' ./$<