#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <clocale>
#include <time.h>
#include <stdlib.h>
using namespace std;

void gabinetmagii(Gracz& g, Lochy& l)
{
	int sklepowyswitch;
	do
	{
		system("cls");
		cout << "GABINET MAGII" << endl << endl;
		cout << "Posiadane z³oto: " << g.getzloto() << endl; //wypisuje ilosc zlota
		for (int i = 0; i < 80; i++) cout << "_"; // odzielenie kresk¹
		cout << endl << "[1] Dodatkowe misje (nie wiêcej ni¿ 5) - 50 z³ota";
		cout << endl << "[2] Eliksir zdrowia (przywraca ¿ycie do pe³na) - 100 z³ota";
		cout << endl << "[3] Wskrzeszenie - 200 z³ota";
		cout << endl << "[4] Wyjœcie do menu" << endl << endl;
		for (int i = 0; i < 80; i++) cout << "_"; // odzielenie kresk¹
		cout << endl << endl << "Wybieram: ";
		cin >> sklepowyswitch;
		switch (sklepowyswitch)
		{
			//zakup misji
		case 1:
			if (g.getzloto() >= 50) // sprawdzenie czy gracza stac na przedmiot
			{
				if (g.getliczbazadan() == 5)
				{
					cout << endl << "Masz maksymaln¹ liczbê mo¿liwych misji!"; //gracz ma 5/5 misji
					Sleep(2000);
					gabinetmagii(g, l); //powrot do sklepu
				}
				else
				{
					g.dodajliczbazadan(); //sfinalizowanie zakupy czyli 5 misji
					g.odejmijzloto(50); //odjecie zlota za zakup
					cout << endl << "Kupiono pakiet 5 misji!";
					Sleep(2000);
					gabinetmagii(g, l);
				}
			}
			else
			{
				cout << "Nie masz wystarczaj¹co du¿o z³ota!!";
				Sleep(2000);
				gabinetmagii(g, l);
			}
			//zakup zdrowia
		case 2:
			if (g.getzloto() >= 100)
			{
				if (g.getzycie() == g.getmaxzycie()) //sprawdzenie czy gracz nie ma maksymalnego poziomu zdrowia
				{
					cout << endl << "Masz max zdrowie!";
					Sleep(2000);
					gabinetmagii(g, l);
				}
				else
					if (g.getzycie() < 1)
					{
						cout << endl << "Potrzebujesz wskrzeszenia!";
						Sleep(2000);
						gabinetmagii(g, l);
					}
					else
					{
						g.odejmijzloto(100); //odjecie zlota za zakup
						g.dodajzycie(); //przywrocenie zdrowia
						cout << endl << "Uleczono!";
						Sleep(2000);
						gabinetmagii(g, l);
					}
			}
			else
			{
				cout << "Nie masz wystarczaj¹co du¿o z³ota!!";
				Sleep(2000);
				gabinetmagii(g, l);
			}
			//wskrzeszenie
		case 3:
			if (g.getzloto() >= 200)
			{
				if (g.getzycie() >= 1)
				{
					cout << endl << "Nie potrzebujesz wskrzeszenia!";
					Sleep(2000);
					gabinetmagii(g, l);
				}
				else
				{
					g.odejmijzloto(200);
					g.dodajzycie();
					cout << endl << "Wskrzeszono!";
					Sleep(2000);
					gabinetmagii(g, l);
				}
			}
			else
			{
				cout << "Nie masz wystarczaj¹co du¿o z³ota!!";
				Sleep(2000);
				gabinetmagii(g, l);
			}
			//wyjscie do menu
		case 4:
			system("cls");
			break;
		default:
			system("cls");
			break;
		}
	} while (sklepowyswitch<=3);
}