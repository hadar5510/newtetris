#include "general.h"
#include <stdio.h>
#include <windows.h> 
#include <process.h> 
#include <iostream>
#include "menu.h"



int main()
{

	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	menu menu;

	menu.gameMenu(false);

}