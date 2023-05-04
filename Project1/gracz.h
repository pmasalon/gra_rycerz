#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <clocale>
#include <time.h>
#include <stdlib.h>
using namespace std;


//---------------------------------------------------------KLASA GRACZ
class Gracz
{
	int lvl;
	int sila;
	int zycie;
	int szczescie;
	int doswiadczenie;
	int zloto;
	int maxzycie; //maksymalne zycie
	int liczbazadan; //liczba zadan mozliwych do wykonania
	string gracz;
	int zbroja = 0;
	int miecz = 0;
	int helm = 0;
	int tarcza = 0;
public:
	void menu();
	void misje();
	void zbrojownia();
	Gracz() //kostruktor
	{
		lvl = 1; sila = 10; zycie = 100; szczescie = 10; doswiadczenie = 0; zloto = 100; maxzycie = 100; liczbazadan = 5;
	}
	//~Gracz(); //destruktor wywala³ b³êdy

	//----------------------------------nazwa gracza
	void setgracz(string g)
	{
		gracz = g;
	}
	string getgracz()
	{
		return gracz;
	}

	//--------------------------------doswiadczenie
	void dodajdoswiadczenie(int d)
	{
		doswiadczenie += d;
	}
	int getdoswiadczenie()
	{
		int d = doswiadczenie;
		return d % 100;
	}
	//--------------------------------------Z£OTO
	void dodajzloto(int g)
	{
		zloto += g;
	}
	void odejmijzloto(int x)
	{
		zloto -= x;
	}
	int getzloto()
	{
		return zloto;
	}
	//-------------------------------------LVL
	void setlvl()
	{
		if (doswiadczenie < 100) lvl = 1;
		else lvl = doswiadczenie / 100 + 1;
	}
	int getlvl()
	{
		setlvl();
		return lvl;
	}
	//-----------------------------------sila
	int getsila()
	{
		return sila;
	}
	//--------------------------------zycie
	int getzycie()
	{
		return zycie;
	}
	int getmaxzycie()
	{
		return maxzycie;
	}
	void dodajzycie()
	{
		zycie = maxzycie;
	}
	void dodajmaxzycie(int z)
	{
		maxzycie += z;
	}
	//------------------------------szczescie
	int getszczescie()
	{
		if (szczescie * 5 / lvl > 50) return 50;
		else return szczescie * 5 / lvl;
	}
	//-----------------------------zadania
	int getliczbazadan()
	{
		return liczbazadan;
	}
	void dodajliczbazadan()
	{
		liczbazadan = 5;
	}
	void odejmijliczbazadan()
	{
		liczbazadan--;
	}
	//------------------------------ekwipunek
	void zalozzbroje(int x)
	{
		zycie -= zbroja;// zdjecie starej zbroi czyli odjecie zycia
		maxzycie -= zbroja; // to samo dla max zycia
		zbroja = 0; //usuniecie z ekwipunku
		zbroja = x; //zalozenie nowej zbroi
		maxzycie += zbroja;
		zycie += zbroja; //dodanie statystyk

	}
	void zalozmiecz(int x)
	{
		sila -= miecz;
		miecz = 0; // zdjecie starej miecz
		miecz = x; //zalozenie nowej miecz
		sila += miecz;
	}
	void zalozhelm(int x)
	{
		zycie -= helm;
		maxzycie -= helm;
		helm = 0; // zdjecie starej helm
		helm = x; //zalozenie nowej helm
		maxzycie += helm;
		zycie += helm;
	}
	void zaloztarcze(int x)
	{
		szczescie -= tarcza;
		tarcza = 0; // zdjecie starej tarczy
		tarcza = x; //zalozenie nowej tarzcy
		szczescie += tarcza;
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
	//---------------------------------walka i lochy
	void wygrana()
	{
		doswiadczenie += 100;
		zloto += 200;
	}
	void walka(int silapotwora, int zyciepotwora)
	{
		bool wygrana = 0;
		int maxzyciepotwora = zyciepotwora;
		system("cls");
		int sz = getszczescie();
		cout << gracz << " VS " << " POTWÓR";
		cout << endl << "si³a: " << sila << " - " << silapotwora;
		cout << endl << "¿ycie: [" << zycie << "/" << maxzycie << "] - [" << zyciepotwora << "/" << maxzyciepotwora << "]";
		int l = rand() % 2 + 1; //losowanie kto pierwszy zaczyna walkê
		if (l == 1) {
			cout << endl << gracz << " rozpoczyna walkê!";
			Sleep(3000);
			system("cls");
			cout << gracz << " VS " << " POTWÓR";
			cout << endl << "si³a: " << sila << " - " << silapotwora;
			cout << endl << "¿ycie: [" << zycie << "/" << maxzycie << "] - [" << zyciepotwora << "/" << maxzyciepotwora << "]";
			do
			{
				//atakuje gracz
				if ((rand() % 100 + 1) <= sz) {
					zyciepotwora -= 2 * sila;
					cout << endl << gracz << " zada³ cios krytyczny! <" << sila * 2 << " pkt. obra¿eñ>";
				}
				//jezeli wylosowano liczbê równ¹ lub mniejsz¹ od % szczêscia to gracz zadaje podwójne obra¿enia

				else {
					zyciepotwora -= sila;
					cout << endl << gracz << " zada³ <" << sila << " pkt. obra¿eñ>";
				}
				Sleep(3000);

				system("cls");
				cout << gracz << " VS " << " POTWÓR";
				cout << endl << "si³a: " << sila << " - " << silapotwora;
				cout << endl << "¿ycie: [" << zycie << "/" << maxzycie << "] - [" << zyciepotwora << "/" << maxzyciepotwora << "]";
				if (zyciepotwora <= 0) {
					wygrana = 1; break;
				}
				//atakuje potwor
				if ((rand() % 100 + 1) <= 25) {
					zycie -= 2 * silapotwora;
					cout << endl << "Potwór zada³ cios krytyczny! <" << silapotwora * 2 << " pkt. obra¿eñ>";
				}
				else {
					zycie -= silapotwora;
					cout << endl << "Potwór zada³ <" << silapotwora << " pkt. obra¿eñ>";
				}
				Sleep(3000);
				system("cls");
				cout << gracz << " VS " << " POTWÓR";
				cout << endl << "si³a: " << sila << " - " << silapotwora;
				cout << endl << "¿ycie: [" << zycie << "/" << maxzycie << "] - [" << zyciepotwora << "/" << maxzyciepotwora << "]";
			} while (zycie > 0 && zyciepotwora > 0);
			if (zycie <= 0) wygrana = 0;

		}
		else
		{
			cout << endl << "Potwór rozpoczyna walkê!";
			Sleep(3000);
			do {
				//atakuje potwor
				if ((rand() % 100 + 1) <= 25) {
					zycie -= 2 * silapotwora;
					cout << endl << "Potwór zada³ cios krytyczny! <" << silapotwora * 2 << " pkt. obra¿eñ>";
				}
				else {
					zycie -= silapotwora;
					cout << endl << "Potwór zada³ <" << silapotwora << " pkt. obra¿eñ>";
				}
				Sleep(3000);

				system("cls");
				cout << gracz << " VS " << " POTWÓR";
				cout << endl << "si³a: " << sila << " - " << silapotwora;
				cout << endl << "¿ycie: [" << zycie << "/" << maxzycie << "] - [" << zyciepotwora << "/" << maxzyciepotwora << "]";
				if (zycie <= 0) {
					wygrana = 0; break;
				}
				//atakuje gracz
				if ((rand() % 100 + 1) <= sz) {
					zyciepotwora -= 2 * sila;
					cout << endl << gracz << " zada³ cios krytyczny! <" << sila * 2 << " pkt. obra¿eñ>";
				}
				else {
					zyciepotwora -= sila;
					cout << endl << gracz << " zada³ <" << sila << " pkt. obra¿eñ>";
				}
				Sleep(3000);
				system("cls");
				cout << gracz << " VS " << " POTWÓR";
				cout << endl << "si³a: " << sila << " - " << silapotwora;
				cout << endl << "¿ycie: [" << zycie << "/" << maxzycie << "] - [" << zyciepotwora << "/" << maxzyciepotwora << "]";

			} while (zycie > 0 && zyciepotwora > 0);
			if (zyciepotwora <= 0) wygrana = 1;
		}
		if (wygrana)
		{
			cout << endl << "Wygra³eœ! Twoje nagrody to: 100 pkt doœwiadczenia i 200 z³ota!";
			dodajdoswiadczenie(100);
			dodajzloto(200);
			Sleep(3000);
		}
		else
			cout << endl << "Niestety przegra³eœ!";
		Sleep(3000);
	}
};