all: prog

prog: main.o
	g++ main.o -o prog

main.o: main.cpp
	g++ -c main.cpp

clean: 
	rm *.o
	rm prog

