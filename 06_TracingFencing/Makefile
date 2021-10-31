GENERATES = move *.o *~ *.so test*

all:	move remove.so

move:	move.o

remove.so:	remove.c
	cc  -shared -fPIC $^ -o $@ -ldl

test:	move remove.so
	echo "1" > test1 && echo "2" > test2;
	./move test1 test2 > /dev/null 2>&1 || [ $$? -eq "0" ] && [ ! -f test1 ] && [ -f test2 ];

	echo "1" > test1 && echo "2" > test2;
	./move test1 > /dev/null 2>&1 || [ $$? -eq "1" ] && [ -f test1 ] && [ -f test2 ];

	strace -e trace=openat -e fault=openat:error=ENOENT:when=3 ./move test1 test2 > /dev/null 2>&1 || [ $$? -eq "4" ] \
	&& [ -f test1 ] && [ -f test2 ];

	strace -e trace=unlink -e fault=unlink:error=ENOENT:when=1 ./move test1 test2 > /dev/null 2>&1 || [ $$? -eq "3" ] \
	&& [ -f test1 ] && [ -f test2 ];

	strace -e trace=openat -e fault=openat:error=ENOENT:when=4 ./move test1 test2 > /dev/null 2>&1 || [ $$? -eq "5" ] \
	&& [ -f test1 ] && [ ! -f test2 ];

	strace -e trace=write -e fault=write:error=EINTR:when=1 ./move test1 test2 > /dev/null 2>&1 || [ $$? -eq "6" ] \
	&& [ -f test1 ] && [ ! -f test2 ];

	strace -e trace=unlink -e fault=unlink:error=ENOENT:when=1 ./move test1 test2  > /dev/null 2>&1 || [ $$? -eq "2" ] \
	&& [ -f test1 ] && [ ! -f test2 ];

	echo "1" > test1_PROTECT && echo "2" > test2_PROTECT;
	LD_PRELOAD="./remove.so" ./move test1 test2_PROTECT > /dev/null 2>&1 || [ $$? -eq "3" ] \
	&& [ -f test1 ] && [ -f test2_PROTECT ];

	LD_PRELOAD="./remove.so" ./move test1_PROTECT test2 > /dev/null 2>&1 || [ $$? -eq "2" ] \
	&& [ -f test1_PROTECT ] && [ ! -f test2 ];

clean:
	rm -f $(GENERATES)
