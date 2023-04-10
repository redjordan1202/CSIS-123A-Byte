/*
Jordan Del Pilar ID 0701246
Assignment #8
main.cpp
Added new DelPilar namespace that includes the menu and byte classes
*/

#include <iostream>
#include <string>
#include <vector>
#include "byte.h"
#include "menu.h"

using namespace std;
using namespace DelPilar;



//Function prototypes
int getNum();
void addTest();
void subTest();
void mulTest();
void divTest();
void indexTest();
void Exit();
void checkNull(Byte b);

int main()
{
    Menu *m = Menu::Instance();

    m->addMenu("1. Test Adding", addTest);
    m->addMenu("2. Test Subtracting", subTest);
    m->addMenu("3. Test Multiplying", mulTest);
    m->addMenu("4. Test Dividing", divTest);
    m->addMenu("5. Test Subscripting", indexTest);
    m->addMenu("6. Exit", Exit);

    m->runMenu();

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
    Menu *m = Menu::Instance();
    int num1, num2;
    cout << "Enter First Number: ";
    num1 = getNum();
    cout << "Enter Second Number: ";
    num2 = getNum();

    Byte *b1 = new Byte(num1);
    checkNull(*b1);
    Byte *b2 = new Byte(num2);
    checkNull(*b2);

    

    if((num1 + num2) <= 255) //If result is then 255 toInt can handle the result
    {
        Byte *b3 = new Byte();
        *b3 = *b1 + *b2;
        checkNull(*b3);

        cout << b1->toInt() << " plus " << b2->toInt() << " equals: "<< endl;
        cout << "As int: " << b3->toInt() << endl;
        cout << "As string: " << b3->toString() << endl;
        delete b3;
    }
    else    //Otherwise use regular arithmetic functions to give result
        cout << b1->toInt() << " plus " << b2->toInt() << " equals: "<< (b1->toInt() + b2->toInt()) << endl;

    m->waitKey();
    delete b1, b2;
}

void subTest()
{
    Menu *m = Menu::Instance();
    int num1, num2;
    cout << "Enter First Number: ";
    num1 = getNum();
    cout << "Enter Second Number: ";
    num2 = getNum();

    Byte *b1 = new Byte(num1);
    checkNull(*b1);
    Byte *b2 = new Byte(num2);
    checkNull(*b2);

    if((num1 - num2) >= 0) //If result is greater then 0 toInt can handle the result
    {
        
        Byte *b3 = new Byte();
        checkNull(*b3);
        
        *b3 = *b1 + *b2;
    
        cout << b1->toInt() << " minus " << b2->toInt() << " equals: "<< endl;
        cout << "As int: " << b3->toInt() << endl;
        cout << "As string: " << b3->toString() << endl;
        delete b3;
    }
    else    //Otherwise use regular arithmetic functions to give result
        cout << b1->toInt() << " minus " << b2->toInt() << " equals: "<< (b1->toInt() - b2->toInt()) << endl;

    m->waitKey();
    delete b1, b2;
}

void mulTest()
{
    Menu *m = Menu::Instance();
    int num1, num2;
    cout << "Enter First Number: ";
    num1 = getNum();
    cout << "Enter Second Number: ";
    num2 = getNum();

    Byte *b1 = new Byte(num1);
    checkNull(*b1);
    Byte *b2 = new Byte(num2);
    checkNull(*b2);

    if((num1 * num2) <= 255)
    {
        
        Byte *b3 = new Byte();
        checkNull(*b3);

        *b3 = *b1 + *b2;
    
        cout << b1->toInt() << " times " << b2->toInt() << " equals: "<< endl;
        cout << "As int: " << b3->toInt() << endl;
        cout << "As string: " << b3->toString() << endl;
        delete b3;
    }
    else 
        cout << b1->toInt() << " times " << b2->toInt() * b2->toInt() << endl;

    m->waitKey();
    delete b1, b2;
}

void divTest()
{
    Menu *m = Menu::Instance();
    int num1, num2;
    cout << "Enter First Number: ";
    num1 = getNum();
    cout << "Enter Second Number: ";
    num2 = getNum();

    Byte *b1 = new Byte(num1);
    checkNull(*b1);
    Byte *b2 = new Byte(num2);
    checkNull(*b2);

    if((num1 / num2) >= 0)
    {
        
        Byte *b3 = new Byte();
        checkNull(*b3);

        *b3 = *b1 + *b2;
    
        cout << b1->toInt() << " divided by " << b2->toInt() << " equals: "<< endl;
        cout << "As int: " << b3->toInt() << endl;
        cout << "As string: " << b3->toString() << endl;
        delete b3;
    }
    else 
        cout << b1->toInt() << " divided " << b2->toInt() << " equals: "<< (b1->toInt() / b2->toInt()) << endl;

    m->waitKey();
    delete b1, b2;
}

void indexTest()
{
    Menu *m = Menu::Instance();
    int num;
    cout << "Enter value for byte: ";
    cin >> num;

    Byte *b1 = new Byte(num);
    checkNull(*b1);

    cout << "Enter bit to view value: ";
    cin >> num;

    cout << b1->operator[](num-1) << endl; //using arrow to operator [] seems to work for whatever reason when just [] doesn't

    m->waitKey();
    delete b1;
}

void Exit()
{
    cout << "Goodbye" << endl;
    exit(0);
}

void checkNull(Byte b)
{
    Menu *m = Menu::Instance();
    if(b == NULL)
        {
            cout << "Unable to allocate memory for Byte object\n";
            m->waitKey();
            return;
        }
}

