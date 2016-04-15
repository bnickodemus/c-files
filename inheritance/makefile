all: prog

prog: inheritance.o
	g++ inheritance.o -o prog

inheritance.o: inheritance.cpp
	g++ -c inheritance.cpp

clean: 
	rm inheritance.o
