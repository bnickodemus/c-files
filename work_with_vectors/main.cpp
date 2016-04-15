// Apr21.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class LL {
public:
    ~LL() {
        cout << "Deleting " << name << endl;
        if (next) {
            delete next;
            next = nullptr;
        }
    }
    LL() : LL("no-name") {
    }
    LL(string name) {
        cout << "Creating " << name << endl;
        this->name = name;
        this->next = nullptr;
        this->last = this;
    }
    string getName() const {
        return name;
    }
    LL* getNext() const {
        return next;
    }
    void add(string name) {
        last->next = new LL{ name };
        last = last->next;
    }
private:
    LL* next;
    LL* last;
    string name;
};

class MEM {
public:
    MEM(const MEM & other) {
        size = other.size;
        capacity = other.capacity;
        nums = new int[capacity];
    }
    MEM() {
        nums = new int[2];
    }
    ~MEM() {
        cout << "deleting memory....";
        delete[] nums;
        cout << "memory deleted. ";
    }
    
    void operator=(const MEM &) = delete;
    
    void push(int value) {
        if (size == capacity) {
            mem_grow();
        }
        nums[size] = value;
        ++size;
    }
    int getSize() const {
        return size;
    }
    int getVal(int index) {
        if (size != 0 && index < size) {
            return *(nums + index);
        }
        else {
            throw out_of_range{ "bad index" };
        }
    }
private:
    int* nums = nullptr;
    int size = 0;
    int capacity = 2;
    
    void mem_grow() {
        capacity *= 2;
        int* temp = new int[capacity];
        for (int i = 0; i < size; ++i) {
            temp[i] = nums[i];
        }
        delete[] nums;
        nums = temp;
        //cout << "end of mem_grow()" << endl;
    }
};

void foo3() {
    LL x{ "Bob" };
    x.add("Sara");
    x.add("Tim");
    x.add("Billy");
    x.add("Marion");
    
    LL* ptr = &x;
    
    while (ptr) {
        cout << ptr->getName() << endl;
        ptr = ptr->getNext();
    }
}

void foo2() {
    MEM x;
    x.push(3); x.push(3); x.push(3); x.push(3); x.push(3);
    cout << "x size:" << x.getSize() << endl;
    MEM y;
    //y = x; // assignment deleted
    cout << "y size:" << y.getSize() << endl;
}

void foo() {
    MEM numbers;
    
    //cout << numbers.getSize() << endl;
    numbers.push(99);
    numbers.push(-1);
    for (int i = 0; i < 20000; ++i) {
        numbers.push(100 + i);
    }
    
    try {
        int val = numbers.getVal(200);
        //cout << val << " size:" << numbers.getSize() << endl;
    }
    catch (out_of_range ex)
    {
        cout << ex.what() << endl;
    }
    cout << numbers.getSize() << endl;
}

int main(int argc, char* argv[])
{
    foo3();
    
    /*
     for (int i = 0; i < 10000000000; ++i) {
     cout << i << "  ";
     foo();
     }
     */
    /*
     double* p = new double;
     double* q = new double[1000];
     
     q[700] = 7.7;
     *p = 34;
     *(q + 700) = 8.8;
     
     //q = p;
     //q[700] = 8.8;
     double d = q[700];
     
     //cout << "d:" << d << endl;
     cout << dec << (q + 0) << " " << (q + 1) << endl;
     */
    return 0;
}



