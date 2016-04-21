all: prog

prog: 3darray.o
	g++ 3darray.o -o prog

3darray.o: 3darray.cpp
	g++ -c 3darray.cpp

clean:
	rm 3darray.o
