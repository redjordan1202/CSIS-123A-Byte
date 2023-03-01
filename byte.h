/*
Jordan Del Pilar ID 0701246
Assignment #6
byte.h
Header file for Byte class. 
No changes needed for this assignment.
*/

#ifndef BYTE
#define BYTE

#include <string>
#include <vector>

using std::vector;
using std::string;

class Byte
{
    private:
    vector <int> bits;
    int bitsToInt() const;

    public:
    //Constructors
    Byte();
    Byte(int val);
    Byte(int ar[8]);
    Byte(vector <int> vec);

    //Core functions
    void setValue(int value);
    int at(int index);
    string toString();
    int toInt() const;

    //Arithmetic functions
    Byte add(int val);
    Byte sub(int val);
    Byte mul(int val);
    Byte div(int val);
    Byte add(const Byte &val);
    Byte sub(const Byte &val);
    Byte mul(const Byte &val); 
    Byte div(const Byte &val); 

    //Overloaded Arithmetic Operators
    Byte operator +(int val); 
    Byte operator -(int val); 
    Byte operator *(int val); 
    Byte operator /(int val);
    Byte operator +(const Byte &val); 
    Byte operator -(const Byte &val); 
    Byte operator *(const Byte &val); 
    Byte operator /(const Byte &val);

    //Overload Assignment Operators
    Byte &operator =(int val);
    Byte &operator =(const Byte &val);

    //Overloaded Equality Operators
    bool operator ==(int val);
    bool operator ==(const Byte &val);
    bool operator !=(int val);
    bool operator !=(const Byte &val);

    //Overload Subscript Operator 
    int operator [](int index);

};

#endif
