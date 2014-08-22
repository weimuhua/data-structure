test:test.o BitTree.o
	cc -o test test.o BitTree.o

test.o:test.c BitTree.h
	cc -c test.c

BitTree.o:BitTree.c BitTree.h
	cc -c BitTree.c

clean:
	rm *.o
