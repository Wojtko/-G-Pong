#include <stdafx.h>
#include <iostream>
#include <vector>
#include "test.h"

using namespace std;

void zapis(vector<int> *p_x)
{
	for (int i = 0; i < 10; i++)
	{
		(*p_x)[i] = i + 1;
	}
}

void odczyt(vector<int> *p_x)
{
	for (int i = 0; i < 10; i++)
	{
		printf("Nr.: %i \n", (*p_x)[i]);
	}
}