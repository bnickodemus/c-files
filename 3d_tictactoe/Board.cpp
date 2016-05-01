#include <iostream>
#include <string>
#include "Board.h"
#include <cmath>
#include <stdlib.h>
#include <ctype.h>
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
	m_pWon = false;
}

Board::~Board()
{

}

void Board::printBoard()
{
	cout << "Board #  Row #  Column #" << endl;
    for (int i=0; i<4; i++) {
        cout << "Board " << i << endl; 
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
	string str;
	bool valid = false;
	bool taken = true;

	do {	
		cout << "Player" << m_player << " please enter a 3 digit number, digits ranging from 0 to 3 (ex. 231)" << endl;
		cin >> str;
			if (!isdigit(str[0]) || !isdigit(str[1]) || !isdigit(str[2]) || (str[0]-'0') > 3 || (str[1]-'0') > 3 || (str[2]-'0') > 3) {
				cout << "you did not enter a number correctly please try again" << endl;
				cin.clear();
				cin.ignore(256,'\n');
				break;
			}
			else {	
				valid = true;
				
				//has the position already been played?
				while (taken == true) {
					//cout << "stuff:" << m_arry[str[0]-'0'][str[1]-'0'][str[2]-'0'] << endl;
					if (m_arry[str[0]-'0'][str[1]-'0'][str[2]-'0'] == '-') { 
						//we're good
						taken = false;
					}
					else {
						//that spot is taken
						cout << "sorry that spot is taken please try again" << endl;
						cin.clear();
						cin.ignore(256,'\n');
						cin >> str;
					}
				}
			}
		}

	while (!valid);
	m_str = str;
}

void Board::placeInput(string str)
{
	//cout << "str:" << str << endl;
	int x = str[0] - '0';
	int y = str[1] - '0';
	int z = str[2] - '0';

	//cout << "x:"<< x << " y:" << y << " z:" << z << endl;
	m_size++;
	m_lastPlayed[0] = x;
	m_lastPlayed[1] = y;
	m_lastPlayed[2] = z;
	if (m_player == 1)
		m_arry[x][y][z] = 'X';
	else
		m_arry[x][y][z] = 'O';
}

void Board::checkWin()
{
	char ch;
	if (m_player == 1)
		ch = 'X';
	else 
		ch = 'O';
	int counter = 0;
	int x,y,z;
	
	x = m_lastPlayed[0];
	y = m_lastPlayed[1];
	z = m_lastPlayed[2];
	
	//check 2d row
	for (int j = 0; j < 4; j++) {
		if (m_arry[x][j][z] == ch)
			counter++;
	}
	if (counter == 4) {
		cout << "Player" << m_player << " has won" << endl;
		m_pWon = true;
	}
	counter = 0; // reset the counter to win variable

	//check 2d column
	for (int k = 0; k < 4; k++) {
		if (m_arry[x][y][k] == ch)
			counter++;
	}
	if (counter == 4) {
		cout << "Player" << m_player << " has won" << endl;
		m_pWon = true;
	}
	counter = 0;
	
	//check 2d diagonal from top to bottom (if j == k)
	for (int i = 0; i < 4; i++) {
		if (m_arry[x][i][i] == ch)
			counter++;
	}
	if (counter == 4) {
		cout << "Player" << m_player << " has won" << endl;
		m_pWon = true;
	}
	counter = 0;
	
	//check 2d diagonal from bottom to top (if j + k == 3)
	for (int j = 4; j > 0; j--) {
		for (int k = 0; k < 4; k++) {
			if (m_arry[x][j][k] == ch)
				counter++;
		}
	}
	if (counter == 4) {
		cout << "Player" << m_player << " has won" << endl;
		m_pWon = true;
	}
	counter = 0;

	//check 3d back
	for (int i = 0; i < 4; i++) {
		if (m_arry[i][y][z] == ch)
			counter++;
	}
	if (counter == 4) {
		cout << "Player" << m_player << " has won" << endl;
		m_pWon = true;
	}
	counter = 0;
	
	//3d diagonal from top left
	for (int i = 0; i < 4; i++) {
		if (m_arry[i][i][i] == ch) {
			counter++;
		}
	}
	if (counter == 4) {
		cout << "Player" << m_player << " has won" << endl;
		m_pWon = true;
	}
	counter = 0;
	
	//3d diagonal from bottom left
	for (int i = 0; i < 4; i++) {
		for (int j = 4; j > 0; j--) {
			for (int k = 0; k < 4; k++) {
				if (m_arry[i][j][k] == ch) 
					counter++;
			}
		}
	}
	if (counter == 4) {
		cout << "Player" << m_player << " has won" << endl;
		m_pWon = true;
	}
	counter = 0;
	
	//3d diagonal from bottom right
	for (int i = 0; i < 4; i++) {
		for (int j = 4; j > 0; j--) {
			for (int k = 4; k > 0; k--) {
				if (m_arry[i][j][k] == ch)
					counter++;
			}
		}
	}
	if (counter == 4) {
		cout << "Player" << m_player << " has won" << endl;
		m_pWon = true;
	}
	counter = 0;
	
	//3d diagonal from top right
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 4; k > 0; k--) {
				if (m_arry[i][j][k] == ch)
					counter++;
			}
		}
	}
	if (counter == 4) {
		cout << "Player" << m_player << " has won" << endl;
		m_pWon = true;
	}
	counter = 0;
	
	//3d diagonal horez
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++) {
			if (m_arry[i][y][k] == ch) 
				counter++;
		}
	}
	if (counter == 4) {
		cout << "Player" << m_player << " has won" << endl;
		m_pWon = true;
	}
	counter = 0;
	
	//3d diagonal vert
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (m_arry[i][j][z] == ch) 
				counter++;
		}
	}
	if (counter == 4) {
		cout << "Player" << m_player << " has won" << endl;
		m_pWon = true;
	}
	counter = 0;


	//switch player
	if (m_player == 1) 
		m_player = 2;
	else 
		m_player = 1;

}






