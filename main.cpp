#include "general.h"
#include <stdio.h>
#include <windows.h> 
#include <process.h> 
#include <iostream>
#include "menu.h"

using namespace std;

int main()
{
	//for (int i = 0; i < 256; i++)
	//{
	//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
	//	cout << i;
	//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//	cout << " ";
	//}
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	Menu menu;

	menu.gameMenu(false);

}