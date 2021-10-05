GENERATES = prog prog-a prog-so README liboutput_static.a liboutput.so
TRASH = *.o *~ o.* *.tmp
CFLAGS = -fPIC

all:	README prog prog-a prog-so

prog:	const.o fun.o prog.o

prog-a: prog.o liboutput_static.a
	cc -L. prog.o -loutput_static -o $@

prog-so: prog.o liboutput.so
	cc -L. prog.o -loutput -o $@

README:	prog
	./$< 2> $@

fun.o:	outlib.h

liboutput_static.a:	const.o fun.o
	ar -rcs $@ $^

liboutput.so: const.o fun.o
	cc  -shared $^ -o $@

test:	prog prog-a	prog-so
	./prog 2> /dev/null 1> prog.tmp
	./prog-a 2> /dev/null 1> prog_a.tmp
	$LD_LIBRARY_PATH='pwd' ./prog-so 2> /dev/null 1> prog_so.tmp
	cmp prog.tmp prog_a.tmp
	cmp prog.tmp prog_so.tmp

	./prog first 1> prog.tmp
	./prog-a first 1> prog_a.tmp
	$LD_LIBRARY_PATH='pwd' ./prog-so first 1> prog_so.tmp
	cmp prog.tmp prog_a.tmp
	cmp prog.tmp prog_so.tmp

	./prog first second third 1> prog.tmp
	./prog-a first second third 1> prog_a.tmp
	$LD_LIBRARY_PATH='pwd' ./prog-so first second third 1> prog_so.tmp
	cmp prog.tmp prog_a.tmp
	cmp prog.tmp prog_so.tmp

clean:
		rm -f $(TRASH)

distclean:	clean
	rm -rf $(GENERATES)