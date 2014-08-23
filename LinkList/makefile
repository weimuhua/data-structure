test:LinkList.o test.o
	cc -o test test.o LinkList.o

LinkList.o:LinkList.c LinkList.h
	cc -c LinkList.c

test.o:test.c LinkList.h
	cc -c test.c

clean:
	rm *.o
