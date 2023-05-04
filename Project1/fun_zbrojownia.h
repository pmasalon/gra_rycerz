#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <clocale>
#include <time.h>
#include <stdlib.h>
using namespace std;

void zbrojownia(Gracz& g, Lochy& l, Zbrojownia& z, string& zbroja, string& miecz, string& helm, string& tarcza, bool& czyzbrojaK, bool& czymieczK, bool& czyhelmK, bool& czytarczaK)
{
	int zbrojowniaswitch;
	do {
		system("cls");
		cout << "ZBROJOWNIA" << endl << endl;
		cout << "Posiadane z�oto: " << g.getzloto() << endl; //wypisuje ilosc zlota
		for (int i = 0; i < 80; i++) cout << "_"; // odzielenie kresk�

		//sprawdzenie czy gracz nie potrzebuje wskrzeszenia

		if (g.getzycie() <= 0) {
			cout << endl << "Potrzebujesz wskrzeszenia!";
			Sleep(1500);
			system("cls");
			menu(g, l);
		}

		if (czyzbrojaK) zbroja = "(zakupiono)"; else zbroja = " "; //sprawdzenie czy dany przedmiot jest ju� kupiony
		if (czymieczK) miecz = "(zakupiono)"; else miecz = " ";
		if (czyhelmK) helm = "(zakupiono)"; else helm = " ";
		if (czytarczaK) tarcza = "(zakupiono)"; else tarcza = " ";
		cout << endl << "[1] Zbroja    | +" << z.getzbroja() << " �ycia    -" << z.getcenazbroi() << " z�ota " << zbroja;
		cout << endl << "[2] Miecz     | +" << z.getmiecz() << " si�y    -" << z.getcenamiecza() << " z�ota " << miecz;
		cout << endl << "[3] Helm      | +" << z.gethelm() << " �ycia    -" << z.getcenahelmu() << " z�ota " << helm;
		cout << endl << "[4] Tarcza    | +" << z.gettarcza() << " szcz�cia    -" << z.getcenatarczy() << " z�ota " << tarcza;
		cout << endl << "[5] Nowy towar| " << "-30 z�ota" << endl;
		cout << "[6]" << " Powr�t do menu" << endl << endl;
		for (int i = 0; i < 80; i++) cout << "_"; // odzielenie kresk�

		
		cout << endl << endl << "Wybieram: "; cin >> zbrojowniaswitch;
		switch (zbrojowniaswitch)
		{
		case 1:
			if (czyzbrojaK) {
				cout << endl << "Ta zbroja ju� zosta�a zakupiona!";
				Sleep(2000);
				system("cls");
				break;
			}
			else
			{
				if (g.getzloto() >= z.getcenazbroi())
				{
					g.zalozzbroje(z.getzbroja()); //zalozenie zbroi
					g.odejmijzloto(z.getcenazbroi()); // zap�ata za ni�
					czyzbrojaK = 1; // znacznik ze zakupiono
					cout << endl << "Zakupiono zbroje!";
					Sleep(2000);
					system("cls");
					break;
				}
				else
				{
					cout << endl << "Nie masz wystarczaj�co du�o z�ota!";
					Sleep(2000);
					system("cls");
					break;
				}
			}
		case 2:
			if (czymieczK) {
				cout << endl << "Ten miecz ju� zosta� zakupiony!";
				Sleep(2000);
				system("cls");
				break;
			}
			else
			{
				if (g.getzloto() >= z.getcenamiecza())
				{
					g.zalozmiecz(z.getmiecz());
					g.odejmijzloto(z.getcenamiecza());
					czymieczK = 1;
					cout << endl << "Zakupiono miecz!";
					Sleep(2000);
					system("cls");
					break;
				}
				else
				{
					cout << endl << "Nie masz wystarczaj�co du�o z�ota!";
					Sleep(2000);
					system("cls");
					break;
				}
			}
		case 3:
			if (czyhelmK) {
				cout << endl << "Ten helm ju� zosta� zakupiony!";
				Sleep(2000);
				system("cls");
				break;
			}
			else
			{
				if (g.getzloto() >= z.getcenahelmu())
				{
					g.zalozhelm(z.gethelm());
					g.odejmijzloto(z.getcenahelmu());
					czyhelmK = 1;
					cout << endl << "Zakupiono helm!";
					Sleep(2000);
					system("cls");
					break;
				}
				else
				{
					cout << endl << "Nie masz wystarczaj�co du�o z�ota!";
					Sleep(2000);
					system("cls");
					break;
				}
			}
		case 4:
			if (czytarczaK) {
				cout << endl << "Ta tarcza ju� zosta�a zakupiona!";
				Sleep(2000);
				system("cls");
				break;
			}
			else
			{
				if (g.getzloto() >= z.getcenatarczy())
				{
					g.zaloztarcze(z.gettarcza());
					g.odejmijzloto(z.getcenatarczy());
					czytarczaK = 1;
					cout << endl << "Zakupiono tarcz�!";
					Sleep(2000);
					system("cls");
					break;
				}
				else
				{
					cout << endl << "Nie masz wystarczaj�co du�o z�ota!";
					Sleep(2000);
					system("cls");
					break;
				}
			}
		case 5:	if (g.getzloto() >= 30)
		{
			czyzbrojaK = 0;
			czymieczK = 0;
			czyhelmK = 0;
			czytarczaK = 0;
			g.odejmijzloto(30);
			cout << endl << "Za chwil� pojawi si� nowy towar!";
			z.losowaniewzbrojowni(g.getlvl());
			system("cls");
			break;
		}
			  else
		{
			cout << endl << "Nie masz wystarczaj�co du�o z�ota!";
			Sleep(2000);
			system("cls");
			break;
		}
		case 6:
			system("cls");
			break;
		default:
			system("cls");
			break;
		}
	} while (zbrojowniaswitch<=5);
}