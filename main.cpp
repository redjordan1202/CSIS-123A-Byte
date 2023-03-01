/*
Jordan Del Pilar ID 0701246
Assignment #6
main.cpp
Testing overloaded operators using menu functions
*/

#include <iostream>
#include <string>
#include <vector>
#include "byte.h"
#include "menu.h"

using namespace std;

Menu m; //Declaring Globally per assignment instructions

//Function prototypes
int getNum();
void addTest();
void subTest();
void mulTest();
void divTest();
void indexTest();
void Exit();

int main()
{
    m.addMenu("1. Test Adding", addTest);
    m.addMenu("2. Test Subtracting", subTest);
    m.addMenu("3. Test Multiplying", mulTest);
    m.addMenu("4. Test Dividing", divTest);
    m.addMenu("5. Test Subscripting", indexTest);
    m.addMenu("6. Exit", Exit);

    m.runMenu();

    return 0;
}


int getNum()
{
    int num;
    cin >> num;
    if(num > 255)
    {
        cout << "Number must be less then 255\n";
        cout << "Setting number to 255\n";
        num = 255;
    }
    return num;
}

void addTest()
{
    int num1, num2;
    cout << "Enter First Number: ";
    num1 = getNum();
    cout << "Enter Second Number: ";
    num2 = getNum();

    Byte b1 = num1;
    Byte b2 = num2;
    if((num1 + num2) <= 255) //If result is then 255 toInt can handle the result
    {
        
        Byte b3 = b1 + b2;
    
        cout << b1.toInt() << " plus " << b2.toInt() << " equals: "<< endl;
        cout << "As int: " << b3.toInt() << endl;
        cout << "As string: " << b3.toString() << endl;
    }
    else    //Otherwise use regular arithmetic functions to give result
        cout << b1.toInt() << " plus " << b2.toInt() << " equals: "<< (b1.toInt() + b2.toInt()) << endl;

    m.waitKey();
}

void subTest()
{
    int num1, num2;
    cout << "Enter First Number: ";
    num1 = getNum();
    cout << "Enter Second Number: ";
    num2 = getNum();

    Byte b1 = num1;
    Byte b2 = num2;
    if((num1 - num2) >= 0) //If result is greater then 0 toInt can handle the result
    {
        
        Byte b3 = b1 - b2;
    
        cout << b1.toInt() << " minus " << b2.toInt() << " equals: "<< endl;
        cout << "As int: " << b3.toInt() << endl;
        cout << "As string: " << b3.toString() << endl;
    }
    else    //Otherwise use regular arithmetic functions to give result
        cout << b1.toInt() << " minus " << b2.toInt() << " equals: "<< (b1.toInt() - b2.toInt()) << endl;

    m.waitKey();
}

void mulTest()
{
    int num1, num2;
    cout << "Enter First Number: ";
    num1 = getNum();
    cout << "Enter Second Number: ";
    num2 = getNum();

    Byte b1 = num1;
    Byte b2 = num2;
    if((num1 * num2) <= 255)
    {
        
        Byte b3 = b1 * b2;
    
        cout << b1.toInt() << " times " << b2.toInt() << " equals: "<< endl;
        cout << "As int: " << b3.toInt() << endl;
        cout << "As string: " << b3.toString() << endl;
    }
    else 
        cout << b1.toInt() << " times " << b2.toInt() << " equals: "<< (b1.toInt() * b2.toInt()) << endl;

    m.waitKey();
}

void divTest()
{
    int num1, num2;
    cout << "Enter First Number: ";
    num1 = getNum();
    cout << "Enter Second Number: ";
    num2 = getNum();

    Byte b1 = num1;
    Byte b2 = num2;
    if((num1 / num2) >= 0)
    {
        
        Byte b3 = b1 / b2;
    
        cout << b1.toInt() << " divided by " << b2.toInt() << " equals: "<< endl;
        cout << "As int: " << b3.toInt() << endl;
        cout << "As string: " << b3.toString() << endl;
    }
    else 
        cout << b1.toInt() << " divided " << b2.toInt() << " equals: "<< (b1.toInt() / b2.toInt()) << endl;

    m.waitKey();
}

void indexTest()
{
    int num;
    cout << "Enter value for byte: ";
    cin >> num;

    Byte b1 = num;

    cout << "Enter bit to view value: ";
    cin >> num;

    cout << b1[num - 1] << endl; //assuming user will count bits from 1 instead of 0

    m.waitKey();
}

void Exit()
{
    cout << "Goodbye" << endl;
    exit(0);
}
