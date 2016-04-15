// visual studio non static data member error



// April 28.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Base {
public:
    Base(int number = 0, string name = "noname")
    : number_{ number }, name_{ name }{
    }
    
    friend ostream& operator<<(ostream & os, const Base & b);
    
    string name() {
        return name_;
    }
    
    int number() {
        return number_;
    }
    
private:
    int number_;
    string name_;
};

class Sub1 : public Base {
public:
    Sub1(int number = 0, string name = "noname", int id = -1)
    : Base{ number, name }, m_id{id} {
        //...
    }
    
    int id() {
        return m_id;
    }
private:
    int m_id;
};

class Sub2 : public Base {
public:
    Sub2(int number = 0, string name = "noname", string id = "")
    : Base{ number, name }, m_id{ id } {
        //...
    }
    
    string toString() {
        stringstream ss;
        ss << "Name: " << name() << " " << "ID: " << m_id;
        return ss.str();
    }
    
    string id() {
        return m_id;
    }
private:
    string m_id;
};

ostream& operator<<(ostream& os, const Base& b) {
    os << b.name_ << " " << b.number_ << endl;
    return os;
}

int main()
{
    Base b1;
    Base b2{ 10, "Betty" };
    Base b3{ 20 };
    //Base b4{ "Paul" }
    Sub1 s0;
    Sub1 s1{ 33, "Sarah", 1 };
    
    cout << b1 << endl << b2 << endl << b3 << endl;
    
    cout << "s1: name " << s1.name()
    << " s1: id " << s1.id() << endl;
    cout << "s0: " << s0 << endl;
    
    b1 = s1;
    
    //s1 = b1;
    
    Sub2 s2{55, "Annie", "xyz10"};
    
    //cout << b1.id() << endl;
    cout << s2.toString() << endl;
    b1 = s2;
    
    vector<Base> objs{ s1, s2, s0, b1 };
    
    
    
    for (auto b : objs) {
        cout << b << endl;
    }
    
    return 0;
}
