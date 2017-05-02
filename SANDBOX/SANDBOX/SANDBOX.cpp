#include <stdafx.h>
#include <iostream>
#include "plansza.h"
#include <conio.h>
#include <windows.h>

using namespace std;

int main()
{
	plansza gra;

	for (;;)
	{
		gra.render();

		if (_kbhit())
		{
			char move;
			move = _getch();
			gra.move(move);
		}

		int temp = gra.getkierunek();
		if(temp == 1 || temp == 2) Sleep(20);
		else Sleep(45);

		COORD cur = { 0, 0 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
	}
	
	system("pause");
	return 0;
}

