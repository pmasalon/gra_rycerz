#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <clocale>
#include <time.h>
#include <stdlib.h>
#include "gracz.h"
#include "zbrojownia.h"
#include "lochy.h"
#include "potwory.h"
#include "misje.h"
#include "fun_menu.h"
#include "fun_misje.h"
#include "fun_zbrojownia.h"
#include "fun_gabinetmagii.h"
#include "fun_ekwipunek.h"
#include "fun_lochy.h"

#pragma warning(disable : 4996) //ignorowanie 'b³êdu' przy getch() przy kompilacji
using namespace std;

//-----------------------------------------

string gracz;
Gracz g;
Misje m;
Zbrojownia z;
Lochy l;
Potwory p;
int m1, m11, m2, m22, m3, m33;
string zbroja, miecz, helm, tarcza; // zmienne potrzebne do sprawdzenia czy s¹ kupione przedmioty (zbrojownia) 
bool czyzbrojaK = 0; //czy zbroja jest ju¿ zakupiona
bool czymieczK = 0;
bool czyhelmK = 0;
bool czytarczaK = 0;

int main()
{
	srand(time(NULL));
	setlocale(LC_CTYPE, "Polish"); //j. polski
	//instrukcja();
	cout << "Podaj nazwê gracza: "; cin >> gracz; cout << endl;
	g.setgracz(gracz); //dodanie nazwy gracza do zmiennych 
	cout << "[WCIŒNIJ DOWOLNY PRZYCISK ABY ZACZ¥Æ]";
	if (getch()) { //oczekiwanie na wcisniecie klawisza
		system("cls");
	} //usuniecie instrukcji
	system("cls");

	int trybswitch;
	do{
		menu(g, l);
		cin >> trybswitch;
		switch (trybswitch)
		{
		case 1: 
			misje(g, l, m, m1, m11, m2, m22, m3, m33);
			break;
		case 2:
			zbrojownia(g, l, z, zbroja, miecz, helm, tarcza, czyzbrojaK, czymieczK, czyhelmK, czytarczaK);
			break;
		case 3:
			gabinetmagii(g, l);
			break;
		case 4:
			ekwipunek(g, l);
			break;
		case 5:
			lochy(g, l, p);
			break;
		case 6:
			system("cls");
			cout << "CZY NA PEWNO CHCESZ WYJŒÆ Z GRY?" << endl << "TWÓJ POSTÊP NIE ZOSTANIE ZAPISANY!" 
				<< endl << "[1] - TAK / [2] - NIE" << endl << endl;
			cout << "Wybieram: ";
			int wyjscie;
			cin >> wyjscie;
			switch (wyjscie)
			{
			case 1: return 0;
				case 2:
					system("cls");
					break;
			}
			break;
		default: system("cls");
			break;
		}
	}while (trybswitch <= 6);

return 0;
}