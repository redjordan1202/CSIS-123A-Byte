/*
Jordan Del Pilar ID 0701246
Assignment #5
main.cpp
Testing new overloaded operators
*/

#include <iostream>
#include <string>
#include <vector>
#include "byte.h"


using namespace std;


int main()
{
    Byte byte1 = 56;
    int ar[8] = {1,1,1,0,0,0,0,0};
    Byte byte2 = ar;
    Byte byte3 = byte1 + byte2;

    cout << "byte1 = " << byte1.toInt() << endl;
    cout << "byte2 = " << byte2.toInt() << endl;
    cout << "byte3 = byte1 + byte = " << byte3.toInt() << endl;

    cout << "byte3 bit at index 2 " << byte3[2] << endl;
    cout << "Result of byte2 == byte3 is " << (byte2==byte3) << endl;

    Byte byte4 = byte3 - byte2;
    cout << byte3.toInt() << " - " << byte2.toInt() << " = " << byte4.toInt() << endl;

    return 0;
}
