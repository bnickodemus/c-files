#ifndef _BOARD_H_INCLUDED
#define _BOARD_H_INCLUDED
#include <string>
#include <cmath>
#include <stdlib.h>
using namespace std;

class Board
{
	public:
	char m_arry [4][4][4];
	string m_str;
	int m_player;
	int m_size;
	int m_lastPlayed [4];
	bool m_pWon;

	Board();
	~Board();
	void printBoard();
	void getInput();
	void placeInput(string str);
	void checkWin();
};
#endif
