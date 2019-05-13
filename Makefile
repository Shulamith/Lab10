main: main.o funcs.o
	g++ -std=c++14 -o main main.o funcs.o

test: test.o funcs.o
	g++ -std=c++14 -o test test.o funcs.o

test.o: test.cpp funcs.h time.h

main.o: main.cpp funcs.h time.h

funcs.o: funcs.cpp funcs.h time.h

clean:
	rm funcs.o main.
