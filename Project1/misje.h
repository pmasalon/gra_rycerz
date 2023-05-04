#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <clocale>
#include <time.h>
#include <stdlib.h>
using namespace std;
//-------------------------------------------KLASA MISJE

class Misje
{
	int los;

public:

	int losujdos()
	{
		los = (rand() % 20) + 1;
		return  los;
	}
	int losujgold()
	{
		los = (rand() % 20) + 1;
		return  los;
	}
	void ladowanie()
	{
		cout << endl;
		for (int i = 1; i < 6; i++)
		{
			cout << i;  Sleep(300); cout << "."; Sleep(300); cout << "."; Sleep(300);
		}
	}


};

