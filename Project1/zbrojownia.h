#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <clocale>
#include <time.h>
#include <stdlib.h>
using namespace std;


//---------------------------------------------------------------------KLASA ZBROJOWNIA

class Zbrojownia
{

	int lvl;
	int los;
	int zbroja; int cenazbroi;  //definicja zmiennych wartosci zbroi, jej ceny 
	int miecz; int cenamiecza;
	int helm; int cenahelmu;
	int tarcza; int cenatarczy;
public:

	Zbrojownia()
	{
		losowaniewzbrojowni(1);
	}

	void setlvl(int l) //pobranie lvl gracza
	{
		lvl = l;
	}

	void losowaniewzbrojowni(int l)
	{
		setlvl(l);
		los = rand() % 2 + 4;
		zbroja = lvl * los;
		cenazbroi = los * 10;
		Sleep(1000);
		los = rand() % 2 + 2;
		miecz = lvl * los;
		cenamiecza = los * 14;
		Sleep(1000);
		los = rand() % 2 + 4;
		helm = lvl * los;
		cenahelmu = los * 10;
		Sleep(1000);
		los = rand() % 2 + 4;
		tarcza = lvl * los;
		cenatarczy = los * 10;
		Sleep(1000);
	}

	int getzbroja()
	{
		return zbroja;
	}
	int getmiecz()
	{
		return miecz;
	}
	int gethelm()
	{
		return helm;
	}
	int gettarcza()
	{
		return tarcza;
	}
	int getcenazbroi()
	{
		return cenazbroi;
	}
	int getcenamiecza()
	{
		return cenamiecza;
	}
	int getcenahelmu()
	{
		return cenahelmu;
	}
	int getcenatarczy()
	{
		return cenatarczy;
	}

};