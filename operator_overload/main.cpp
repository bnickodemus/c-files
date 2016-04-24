#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Numbers {
public:
    Numbers() : nums{1,2,3}{};
    Numbers(const vector<int> & someNums)
    : nums{someNums} {
        
    }
    void insertNumber(int num) {
        nums.push_back(num);
    }
    const vector<int> getNums() const {
        return nums;
    }
    
    long operator+(Numbers other) {
        Numbers result{*this};
        
        //for (auto i : this->nums) {  // (*this.nums)        these are the same. we have to deref the pointer. the dot has higher precidence . that element in the memory
        //    result.;
        //}
        
        for (auto i : other.getNums()) {     // objects of the same class can access each others private data. so we have access to nums
            result.insertNumber(i);
        }
        return result;
    }
    
    int operator[](unsigned i) const {
        return this->getNums()[i];
    }
    
    bool operator !=(const Number & other) {
        return !(*this == other);
    }
    
    
    bool operator==(const Number & other) {
        bool result{ this->size() ==
            other.getNums().size());
            
            if (!result) {
                return result;
            }
            
            for (auto i = 0; i < this->getNums.size(); ++i) {
                if ((*this)[i] != other[i]) {
                    return false;
                }
            }
            return true;
        }
        
        long sum() {
            long result = 0;
            for (auto i
                 }
                 
                 private:
                 vector<int> nums;
                 };
                 
                 ostream & operator << (ostream & os, const Numbers & x) {
                     for (auto i : x.getNums()) {
                         os << i << " ";
                     }
                     os << endl;
                     return os;
                 };
                 
                 void foo() {
                     ofstream ost{ "C:\\data.txt", ios_base::binary };
                     for (int i = 1; i <= 10; ++i) {
                         ost << i << endl;
                     }
                     ost.close();
                     cout << "File written." << endl;
                 }
                 
                 int main(int argc, const char * argv[]) {
                     cout << "Hello Broc World" << endl;
                     for (int i = 1; i <= 16; ++i) {
                         //cout << dec << i << '\t' << hex << i
                         //    << '\t' << oct << i << '\t' << endl;
                     }
                     //foo();
                     Numbers x;
                     vector<int> vals{ 4, 5, 6 };
                     Numbers y{vals};
                     x.insertNumber(10);
                     Numbers z{ x + y };
                     
                     cout << "x[0]" << x[0] << endl;
                     
                     cout << (x + y + z).sum()) << endl;
                     
                     Numbers t;
                     Numbers s;
                     cout << "t == z?" << (t == z) << endl;
                     cout << "t == z?" << (t != z) << endl;
                     //bool alpha
                     //cout << (x + y) << endl;  // we overloaded the plus oppperator
                     
                 }