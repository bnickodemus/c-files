#include <iostream>
#include <string>
#include "Board.h"
#include <cmath>
#include <stdlib.h>
using namespace std;

Board::Board()
{	
	for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            for (int k=0; k<4; k++) {
                m_arry[i][j][k] = '-';
            }
        }
    }
	m_player = 1;
	m_size = 0;
}

Board::~Board()
{

}

void Board::printBoard()
{
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            for (int k=0; k<4; k++) {
                cout << m_arry[i][j][k] << " ";
                if (k == 3)
                    cout << endl;
			}
            if (j == 3)
                cout << endl;
        }
    }

}

void Board::getInput()
{
	char input[256];
	cout << "player" << m_player << " please enter a board a row and a cell (ex 111)" << endl;
	cin >> input;
	/*
	int istr;
	istr = atoi(input);
	
	while (!isnan(istr)) {
		cout << "you did not enter a number, please try again" << endl;
		cin.clear();
		cin.ignore();
		cout << "please enter another 3 digit number" << endl;
		cin >> input;
	}
	*/
	cout << "you entered:" << input << endl;
	m_str = input;
	if (m_player == 1) 
		m_player = 2;
	else 
		m_player = 1;
}

void Board::placeInput(string str)
{
	cout << "str:" << str << endl;
	
	int x = str[0] - '0';
	int y = str[1] - '0';
	int z = str[2] - '0';

	//cout << "x:"<< x << " y:" << y << " z:" << z << endl;
	if (m_player == 1)
		m_arry[x][y][z] = 'X';
	if (m_player == 2)
		m_arry[x][y][z] = 'O'; 
	m_size++;
	m_lastPlayed[0] = x;
	m_lastPlayed[1] = y;
	m_lastPlayed[2] = z;
}

void Board::checkWin()
{
	int counter = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {	
				if(m_lastPlayed[1] == m_lastPlayed[2]) {  //if (j == k)  // check top to bottom diagonal
					counter++;
				}
			}
		}
	}
	if (counter == 3) 
		cout << "Player" << m_player << " has won" << endl;
}





