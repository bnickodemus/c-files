

//
//  main.cpp
//  Test
//
//  Created by Broc Nickodemus on 6/8/15.
//  Copyright (c) 2015 Broc Nickodemus. All rights reserved.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main() {
    char *text;
    text = new char[];
    
    cout << "Insert the string" << endl;
    cin >> text;
    
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' || text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U') {
            text[i] = ' ';
        }
    }
    cout << text;
    return 0;
}
