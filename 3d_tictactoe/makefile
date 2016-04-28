all: prog

prog: Game.o Board.o
		g++ Game.o Board.o -o prog

Board.o: Board.cpp
		g++ -c Board.cpp

Game.o: Game.cpp
		g++ -c Game.cpp

clean:
		rm *.o
		rm prog

