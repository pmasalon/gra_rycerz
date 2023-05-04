#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <clocale>
#include <time.h>
#include <stdlib.h>
using namespace std;
//--------------------------------------KLASA POTWORY


class Potwory
{
	int sila = 15;
	int zycie = 110;
	int const szczescie = 25;
public:
	void setsila(int nrlochu, int nrpotwora)
	{
		int s = nrlochu;
		int z = nrpotwora;
		int x = s * z * 5 - 5;
		sila += x;
	}
	void setzycie(int nrlochu, int nrpotwora)
	{
		int s = nrlochu;
		int z = nrpotwora;
		int x = s * z * 10 - 10;
		zycie += x;
	}
	int getsila()
	{
		return sila;
	}
	int getzycie()
	{
		return zycie;
	}

};