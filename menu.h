/*
Jordan Del Pilar ID 0701246
Assignment #8
menu.h
Header file for Menu class. 
Wrapped class in DelPilar Namespace. Also added Singleton design pattern to class
*/

#ifndef MENU
#define MENU
#include <vector>
#include <string>

using std::vector;

const int MAXCOUNT = 20;

namespace DelPilar
{
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
			static Menu *pInstance;
		public:
			Menu();
			void addMenu(std::string Description, void (*f)());
			void runMenu();
			void waitKey();
			static Menu *Instance();
	};
}
#endif