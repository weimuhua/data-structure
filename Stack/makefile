ExpEvaluation:ExpEvaluation.o Stack.o
	cc -o ExpEvaluation ExpEvaluation.o Stack.o

Stack.o:Stack.c Stack.h
	cc -c Stack.c

ExpEvaluation.o:ExpEvaluation.c Stack.h
	cc -c ExpEvaluation.c

clean:
	rm *.o
