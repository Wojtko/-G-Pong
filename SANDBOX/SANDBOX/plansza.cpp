#include "stdafx.h"
#include "plansza.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

plansza::plansza()
	:playerx (2)
	, playery1 (8)
	, splayerx (WIDTH-3)
	, splayery1 (8)
	, ballx (WIDTH/2)
	, bally (10)
	, kierunek(1)
	, player (0)
	, splayer(0)
{
	pola.resize(HEIGTH);
	for (int i = 0; i < HEIGTH; i++)
	{
		pola[i].resize(WIDTH);
	}

	for (int y = 0; y < HEIGTH; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if ((y == HEIGTH-1) || (y == 0) || (x == WIDTH-1) || (x == 0)) pola[y][x] = 'X';
			else if (x == 30) pola[y][x] = '|';
			else if (x == 14 && y == 5) pola[y][x] = '0';
			else if (x == 44 && y == 5) pola[y][x] = '0';
			else pola[y][x] = ' ';
		}
	}
}

plansza::~plansza()
{
}

void plansza::render()
{
	int playery2 = playery1 + 1;
	int playery3 = playery1 + 2;
	int playery4 = playery1 + 3;
	int playery5 = playery1 + 4;
	int splayery2 = splayery1 + 1;
	int splayery3 = splayery1 + 2;
	int splayery4 = splayery1 + 3;
	int splayery5 = splayery1 + 4;


	char one[9];
	char two[9];

	_itoa_s(player, one, 10);
	_itoa_s(splayer, two, 10);

	if (((bally == playery3) && (ballx == playerx))) kierunek = 1;
	else if (((bally == playery2) && (ballx == playerx))) kierunek = 3;
	else if (((bally == playery4) && (ballx == playerx))) kierunek = 5;
	else if (((bally == playery1) && (ballx == playerx))) kierunek = 7;
	else if (((bally == playery5) && (ballx == playerx))) kierunek = 9;

	if (((bally == splayery3) && (ballx == splayerx))) kierunek = 2;
	else if (((bally == splayery2) && (ballx == splayerx))) kierunek = 4;
	else if (((bally == splayery4) && (ballx == splayerx))) kierunek = 6;
	else if (((bally == splayery1) && (ballx == splayerx))) kierunek = 8;
	else if (((bally == splayery5) && (ballx == splayerx))) kierunek = 100;

	if (bally <= 1)
	{
		if (kierunek % 2 == 0) kierunek = 10;
		else kierunek = 11;
	}
	else if (bally >= HEIGTH-2)
	{
		if (kierunek % 2 == 0) kierunek = 12;
		else kierunek = 13;
	}

	ball();

	for (int y = 0; y < HEIGTH; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if ((playery1 == y && playerx == x) || (playery2 == y && playerx == x) || (playery3 == y && playerx == x) || (playery4 == y && playerx == x) || (playery5 == y && playerx == x)) pola[y][x] = 'H';
			else if ((splayery1 == y && splayerx == x) || (splayery2 == y && splayerx == x) || (splayery3 == y && splayerx == x) || (splayery4 == y && splayerx == x) || (splayery5 == y && splayerx == x)) pola[y][x] = 'H';
			else if ((y == HEIGTH - 1) || (y == 0) || (x == WIDTH - 1) || (x == 0)) pola[y][x] = 'X';
			else if (bally == y && ballx == x) pola[y][x] = 'O';
			else if ((x != 30) && (y != HEIGTH - 1) && (y != 0) && (x != WIDTH - 1) && (x != 0))
			{
				if ((x == 44 && y == 5) || (x == 14 && y == 5))
				{
					if (x == 14 && y == 5) pola[y][x] = *one;
					else if (x == 44 && y == 5) pola[y][x] = *two;
				}
				else pola[y][x] = ' ';
			}
			else if (x == 30) pola[y][x] = '|';
			
			
			printf("%c", pola[y][x]);
		}
		printf("\n");
	}

	
	plansza::ballx = ballx;

}

int plansza::getx()
{
	return playerx;
}

int plansza::gety()
{
	return playery1;
}

int plansza::sgetx()
{
	return splayerx;
}

int plansza::sgety()
{
	return splayery1;
}

int plansza::getbally()
{
	return bally;
}

int plansza::getballx()
{
	return ballx;
}

int plansza::getkierunek()
{
	return kierunek;
}

void plansza::move(char ch)
{
	switch (ch)
	{
		case 'w':
			playery1--;	
			if (playery1 <= 0) playery1 = 1;
			break;
		case 's':
			playery1++;
			if (playery1 >= HEIGTH - 6) playery1 = HEIGTH - 6;
			break;
		case 'i':
			splayery1--;
			if (splayery1 <= 0) splayery1 = 1;
			break;
		case 'k':
			splayery1++;
			if (splayery1 >= HEIGTH - 6) splayery1 = HEIGTH - 6;
			break;
	}
}

void plansza::ball()
{
	if (kierunek == 1) ballx++;
	else if (kierunek == 2) ballx--;
	else if (kierunek == 3)
	{
		ballx++;
		bally--;
	}
	else if (kierunek == 4)
	{
		ballx--;
		bally--;
	}
	else if (kierunek == 5)
	{
		ballx++;
		bally++;
	}
	else if (kierunek == 6)
	{
		ballx--;
		bally++;
	}
	else if (kierunek == 7)
	{
		ballx++;
		bally -= 2;
	}
	else if (kierunek == 8)
	{
		ballx--;
		bally -= 2;
	}
	else if (kierunek == 9)
	{
		ballx++;
		bally += 2;
	}
	else if (kierunek == 100)
	{
		ballx--;
		bally += 2;
	}
	else if (kierunek == 10)
	{
		if (bally < 1)
		{
			ballx--;
			bally += 3;
		}
		else if (bally >= 1)
		{
			ballx--;
			bally++;
		}
	}
	else if (kierunek == 11)
	{
		if (bally < 1)
		{
			ballx++;
			bally += 3;
		}
		else if (bally >= 1)
		{
			ballx++;
			bally++;
		}
	}
	else if (kierunek == 12)
	{ 
		if (bally > HEIGTH - 2)
		{
			ballx--;
			bally -=3;
		}
		else if (bally <= HEIGTH - 2)
		{
			ballx--;
			bally--;
		}
	}
	else if (kierunek == 13)
	{
		if (bally > HEIGTH - 2)
		{
			ballx++;
			bally -= 3;
		}
		else if (bally <= HEIGTH - 2)
		{
			ballx++;
			bally--;
		}
	}

	if (ballx <= 0)
	{
		splayer++;
		ballx = WIDTH / 2;
		if (splayer == 10)
		{
			splayer = 0;
			player = 0;
		}
	}
	else if (ballx >= 59)
	{
		player++;
		ballx = WIDTH / 2;
		if (player == 10)
		{
			splayer = 0;
			player = 0;
		}
	}
}