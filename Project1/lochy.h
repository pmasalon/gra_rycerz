#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <clocale>
#include <time.h>
#include <stdlib.h>
using namespace std;
//-----------------------KLASA LOCHY


class Lochy
{
	int nrLochu = 1;
	int nrPotwora = 1;
public:
	int getNrLochu()
	{
		return nrLochu;
	}
	int getNrPotwora()
	{
		return nrPotwora;
	}
	void setNrLochu()
	{
		if (nrPotwora == 11)
		{
			nrLochu++;
			nrPotwora = 1;
		}
	}
	void setNrPotwora()
	{
		nrPotwora++;
	}
};





