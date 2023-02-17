/*
Jordan Del Pilar ID 0701246
Assignment #5
byte.h
Header file for Byte class. 
Added overloaded operators. Added some comments to clean up code a bit
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
    int bitsToInt();

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
    int toInt();

    //Arithmetic functions
    Byte add(int val);
    Byte sub(int val);
    Byte mul(int val);
    Byte div(int val);
    Byte add(Byte &val);
    Byte sub(Byte &val);
    Byte mul(Byte &val); 
    Byte div(Byte &val); 

    //Overloaded Arithmetic Operators
    Byte operator +(int val); 
    Byte operator -(int val); 
    Byte operator *(int val); 
    Byte operator /(int val);
    Byte operator +(Byte &val); 
    Byte operator -(Byte &val); 
    Byte operator *(Byte &val); 
    Byte operator /(Byte &val);

    //Overload Assignment Operators
    Byte operator =(int val);
    Byte operator =(int ar[8]);
    Byte operator =(vector <int> vec);
    Byte operator =(Byte &val);

    //Overloaded Equality Operators
    bool operator ==(int val);
    bool operator ==(Byte &val);
    bool operator !=(int val);
    bool operator !=(Byte &val);

    //Overload Subscript Operator 
    int operator [](int index);

};

#endif
