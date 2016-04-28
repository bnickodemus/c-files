#include <iostream>
#include <string>
#include "Board.h"

using namespace std;

int main()
{
	cout << endl;
	
	Board * gameBoard = new Board();
	gameBoard->printBoard();

	while (gameBoard->m_size < 65) {
		
	gameBoard->getInput();
	gameBoard->placeInput(gameBoard->m_str);
	gameBoard->printBoard();
	
	}

	return 0;
}
