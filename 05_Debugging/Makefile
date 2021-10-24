GENERATES = range *.o *~ o.* *.output

all:	range

range:	range.c
	cc -O0 -g $^ -o $@

test:	range
	gdb --batch --quiet --command=gdb_test1 --args ./range | grep '^@@@' | cut -c 4- | cmp test1_target
	gdb --batch --quiet --command=gdb_test2 --args ./range | grep '^@@@' | cut -c 4- | cmp test2_target

clean:
	rm -f $(GENERATES)
