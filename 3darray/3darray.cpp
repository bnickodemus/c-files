#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void print(int arry[][1][3]) {
    cout << "day: high: low:" << endl;
    for(int i=0;i<31;++i) {
        for(int j=0;j<1;++j) {
            for(int k=0;k<3;++k) {
                printf("%i ", arry[i][j][k]);
            }
        }
    }
    cout << endl << endl;
}

void findAverageHigh(int arry[][1][3]) {
    int counter = 0;
    for(int i=0;i<31;++i) {
        for(int j=0;j<1;++j) {
            //cout << "high: " << arry[i][j][1] << endl;
            counter += arry[i][j][1];
        }
    }
    counter /= 31;
    cout << "Average High:" << counter << endl;
}
void findAverageLow(int arry[][1][3]) {
    int counter = 0;
    for(int i=0;i<31;++i) {
        for(int j=0;j<1;++j) {
            //cout << "high: " << arry[i][j][2] << endl;
            counter += arry[i][j][2];
        }
    }
    counter /= 31;
    cout << "Average Low:" << counter << endl;
}

void findHighestTemp(int arry[][1][3]) {
    int high = arry[0][0][1];
    for(int i=0;i<31;++i) {
        for(int j=0;j<1;++j) {
            if (high < arry[i][j][1])
                high = arry[i][j][1];
        }
    }
    cout << "Highest High:" << high << endl;
}

void findLowestTemp(int arry[][1][3]) {
    int low = arry[0][0][2];
    for(int i=0;i<31;++i) {
        for(int j=0;j<1;++j) {
            if (low > arry[i][j][2])
                low = arry[i][j][2];
        }
    }
    cout << "Lowest Low:" << low << endl;
}

void daysFiftyFour(int arry[][1][3]) {
    int days = 0;
    for(int i=0;i<31;++i) {
        for(int j=0;j<1;++j) {
            if (arry[i][j][1] == 54)
                days++;
        }
    }
    cout << "High days with 54 degrees:" << days << endl;
}

void daysBelowFreezing(int arry[][1][3]) {
    int days = 0;
    for(int i=0;i<31;++i) {
        for(int j=0;j<1;++j) {
            if (arry[i][j][2] < 32)
                days++;
        }
    }
    cout << "Low days that are below freezing:" << days << endl;
}

int main() {
    cout << "hw3" << endl;
    
    int arry[31][1][3] = {
        {{1,48,25}},
        {{2,48,25}},
        {{3,48,26}},
        {{4,48,26}},
        {{5,48,26}},
        {{6,49,26}},
        {{7,49,26}},
        {{8,49,26}},
        {{9,50,26}},
        {{10,50,27}},
        {{11,50,27}},
        {{12,50,27}},
        {{13,50,27}},
        {{14,51,27}},
        {{15,51,28}},
        {{16,51,28}},
        {{17,51,28}},
        {{18,52,28}},
        {{19,52,28}},
        {{20,52,28}},
        {{21,52,28}},
        {{22,52,28}},
        {{23,53,29}},
        {{24,53,29}},
        {{25,53,29}},
        {{26,53,29}},
        {{27,53,29}},
        {{28,53,29}},
        {{29,54,29}},
        {{30,54,29}},
        {{31,54,29}},
    };
    
    print(arry);
    findAverageHigh(arry);
    findAverageLow(arry);
    findHighestTemp(arry);
    findLowestTemp(arry);
    daysFiftyFour(arry);
    daysBelowFreezing(arry);
}


