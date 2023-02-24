/*
Jordan Del Pilar ID 0701246
Assignment #5
byte.cpp
CPP file for Byte class
Updated to add overloaded operators. cleaned up code a little bit
bit.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "byte.h"

using std::string;
using std::stringstream;
using std::vector;

int Byte::bitsToInt() const
{
    int mask = 1;
    int bit = this->bits[0];
    int result = 0;
    int num = 0;
    
    for(int i=0; i < 8; i++)
    {
        if(i > 0)
        {
            mask = (mask << 1);
            bit = (this->bits[i] << i);
        }
        result = (mask&bit);
        if(result > 0)
            num += result;
    }
    
    return num;
}

//Constructors
Byte::Byte()
{
    Byte(0);
}

Byte::Byte(int val)
{
    this->bits.resize(8, 0);
    this->setValue(val);
}

Byte::Byte(int ar[8])
{
    this->bits.resize(8, 0);
    for(int i = 7; i >= 0; i--)
    {
        if((ar[i] != 0)&&(ar[i] != 1)) //check if number is 1 or 0
        {
            setValue(0);                //If not set value to 0
            return;
        }
        else
            this->bits[i] = ar[i];
    }
}

Byte::Byte(vector <int> vec)
{
    this->bits.resize(8, 0);
    for(int i = 0; i < 8; i++)
    {
        if((vec[i] != 0)&&(vec[i] != 1)) //check if number is 1 or 0
        {
            setValue(0);                //If not set value to 0
            return;
        }
        else
            this->bits[i] = vec[i];
    }
}

//Core Functions
void Byte::setValue(int value)
{
    int mask = 1;
    int result = 0;

    for(int i=0; i < 8; i++)
    {
        if(i > 0)
            mask = (mask << 1);
        result = (mask&value);
        if(result > 0)
            this->bits[i] = 1;
        else
            this->bits[i] = 0;
    }
}

int Byte::at(int index)
{
    return this->bits[index];
}

string Byte::toString()
{
    stringstream str;
    
    for(int i=7; i >= 0; i--)
        str << this->bits[i];
    
    return str.str();
}

int Byte::toInt() const
{
    return this->bitsToInt();
}

//Arithmetic Functions
Byte Byte::add(int val)
{
    int total = this->toInt() + val;
    return Byte(total);
}

Byte Byte::sub(int val)
{
    int total = this->toInt() - val;
    return Byte(total);
}

Byte Byte::mul(int val)
{
    int total = this->toInt() * val;
    return Byte(total);
}

Byte Byte::div(int val)
{
    int total = this->toInt() / val;
    return Byte(total);
}

Byte Byte::add(const Byte &val) 
{
    int total = this->toInt() + val.toInt();
    return Byte(total);
}

Byte Byte::sub(const Byte &val) 
{
    int total = this->toInt() - val.toInt();
    return Byte(total);
}

Byte Byte::mul(const Byte &val) 
{
    int total = this->toInt() * val.toInt();
    return Byte(total);
}

Byte Byte::div(const Byte &val) 
{
    int total = this->toInt() / val.toInt();
    return Byte(total);
}

//Overloaded Arithmetic Operators
Byte Byte::operator +(int val) 
{
    return this->add(val);
}

Byte Byte::operator -(int val) 
{
    return this->sub(val);
}

Byte Byte::operator *(int val) 
{
    return this->mul(val);
}

Byte Byte::operator /(int val) 
{
    return this->div(val);
}

Byte Byte::operator +(const Byte &val) 
{
    return this->add(val);
}

Byte Byte::operator -(const Byte &val) 
{
    return this->sub(val);
}

Byte Byte::operator *(const Byte &val) 
{
    return this->mul(val);
}

Byte Byte::operator /(const Byte &val) 
{
    return this->div(val);
}

//Overload Assignment Operators
Byte &Byte::operator =(int val)
{
    this->setValue(val);
    return *this;
}

Byte &Byte::operator =(const Byte &val)
{
    this->setValue(val.toInt());
    return *this;
}

//Overloaded Equality Operators
bool Byte::operator ==(int val)
{
    if(this->toInt() == val)
        return 1;
    else
        return 0;
}

bool Byte::operator ==(const Byte &val)
{
    return(*this == val.toInt());
}

bool Byte::operator !=(int val)
{
    return !(*this == val);
}

bool Byte::operator !=(const Byte &val)
{
    return !(*this == val);
}

//Overload Subscript Operator
int Byte::operator [](int index)
{
    return this->at(index);
}
