#include<iostream>
#include<string.h>
#include<fstream>
#include<stdio.h>
#include<vector>
#include <ctype.h>
using namespace std;

bool is_palindrome( string str ) {
    if (str.length() >=3)
        return equal( str.begin(), str.end(), str.rbegin() ) ;
    else {
        return false;
    }
}

void removeSpaces(char *str)
{
    int count = 0;
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ')
            str[count++] = str[i];
    str[count] = '\0';
}

void ParseString(string str) {
    string buffer;
    string tmp;
    //vector<vector<string>> v;
    vector<string> sent;
    vector<string> word;
    int j,k = 0;
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != '.') {// found period
            buffer.push_back(str[i]);
            if (str[i] != ' ') {// found word
                tmp.push_back(str[i]);
            }
            else {// word
                word.push_back(tmp);
                k++;
                tmp.erase(0, tmp.length());
            }
        }
        else {// period
            sent.push_back(buffer);
            j++;
            buffer.erase(0, buffer.length());
        }
    }

    string pass;
    char c;
    string good;
    for (int i = 0; i < word.size(); i++) {
        //cout << word[i] << endl;
        pass = word[i];
        for (int j = 0; j < pass.size(); j++) {
            c = pass[j];
            //tolower(c);
            if(c<='Z' && c>='A')
                c = c-('Z'-'z');
            //cout << "c:" << c << endl;
            good.push_back(c);
        }
        word[i] = good;
        good = "";
    }
    
    //check if sentences are pal's
    string buff = "";
    for (int i = 0; i < word.size(); i++) {
        for (int j = i; j < word.size(); j++) {
            buff.append(word[j]);
            if (is_palindrome(buff) == true) {
                cout << "pal:" << buff << " ind:" << j << endl;
            }
            //cout << buff << endl << endl;
        }
        buff = "";
    }
    //buff.erase(0,1);
    //buff.pop_back();
    
    //check if any words are pal's
    for (int i = 0; i < word.size(); i++) {
        //cout << word[i] << endl;
        if (is_palindrome(word[i]))
            cout << "pal:" << word[i] << " ind:" << i << endl;
    }
}

string getInput() {
    string line;
    string str;
    ifstream ifile ("/Users/Broc/Desktop/data.txt");
    if (ifile.is_open()) {
        while (getline(ifile,line)) {
            //cout << line;
            str += line;
        }
        ifile.close();
    }
    return str;
}

int main(int argc, const char * argv[]) {
    cout << "prog" << endl;
    
    string str;
    str = getInput();
    
    //str.erase(remove(str.begin(), str.end(), ' '), str.end());
    //str.erase(remove(str.begin(), str.end(), '.'), str.end());
    str.erase(remove(str.begin(), str.end(), ','), str.end());
    str.erase(remove(str.begin(), str.end(), '|'), str.end());
    str.erase(remove(str.begin(), str.end(), '?'), str.end());
    str.erase(remove(str.begin(), str.end(), '-'), str.end());
    
    ParseString(str);
    
    cout << endl;
}
