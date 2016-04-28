#include <iostream>
#include <string>

using namespace std;

int main() {
	cout << "Prog" << endl;
	
	//int board  
	//populate with dashes and bars
	//print starting board
	//
	//while game isn't won
	//prompt player x for input
	//update
	//check win 
	//print board
	
    char arry[4][4][4];
    
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            for (int k=0; k<4; k++) {
                arry[i][j][k] = '-';
                cout << arry[i][j][k] << " ";
				if (k == 3) {
					cout << endl;
				}
            }
			if (j == 3) {
				cout << endl;
			}
        }
    }
    
}





