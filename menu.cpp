/*
Jordan Del Pilar ID 0701246
Assignment #8
menu.cpp
cpp file for Menu class
Wrapped class in DelPilar Namespace. Also added Singleton design pattern to class
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <vector>
#include "Menu.h"

using namespace std;

namespace DelPilar
{
	Menu::Menu(): count(0)
	{
		mi.resize(MAXCOUNT);
	}

	void Menu::addMenu(string Description, void (*f)())
	{
		if (count < MAXCOUNT)
		{
			this->mi[count].func = f;
			this->mi[count].descript.insert(0, Description);
			count++;
		}
	}

	void Menu::runMenu()
	{
		for (;;)
		{
			system("CLS");
			for (int i = 0; i < count; i++)
			{
				cout << this->mi[i].descript << endl;
			}
			runSelection();
		}
	}

	void Menu::runSelection()
	{
		int select;
		cin >> select;
		if (select <= count)
			this->mi[select - 1].func();
	}

	void Menu::waitKey()
	{
		cout << "Press any key to continue" << endl;
		while (!_kbhit()); // kbhit is deprecated. use _kbhit
		fflush(stdin);
	}

	Menu *Menu::pInstance = NULL;

	Menu *Menu::Instance()
	{
		if(pInstance == NULL)
			pInstance = new Menu;
		
		return pInstance;
	}
}