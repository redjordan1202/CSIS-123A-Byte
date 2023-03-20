/*
Jordan Del Pilar ID 0701246
Assignment #7
menu.h
Header file for Menu class. 
*/

#ifndef MENU
#define MENU
#include <vector>
#include <string>

using std::vector;

const int MAXCOUNT = 20;

struct menuItem
{
	void (*func) ();
	std::string descript;
};

class Menu
{
	private:
		vector <menuItem> mi;
		int count = 0;
		void runSelection();
	public:
		Menu();
		void addMenu(std::string Description, void (*f)());
		void runMenu();
		void waitKey();
};
#endif