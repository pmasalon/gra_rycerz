#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <clocale>
#include <time.h>
#include <stdlib.h>
using namespace std;

void misje(Gracz& g, Lochy& l, Misje& m, int& m1, int& m11, int& m2, int& m22, int& m3, int& m33)
{
	int misjaswitch;
	do {
	system("cls");
	cout << "MISJE" << endl;

	for (int i = 0; i < 80; i++) cout << "_"; // odzielenie kresk�

	//pomi�dzy ka�dym losem liczby jest sekundowa przerwa aby liczby by�y r�ne ( liczba jest losowana na podstawie danej sekundy)

	//sprawdzenie czy gracz nie potrzebuje wskrzeszenia

	if (g.getzycie() <= 0) {
		cout << endl << "Potrzebujesz wskrzeszenia!";
		Sleep(1500);
		system("cls");
		return;
	}

	cout << endl << "Wybierz misj�:" << endl; cout << "Ilo�� misji do wykonania: [" << g.getliczbazadan() << "/5]" << endl;

	//-----------losowanie exp i gold misja 1
	cout << "[1]" << endl;
	m1 = m.losujdos(); Sleep(1000); //przypisanie do zmiennej ilo�ci doswiadczenia
	m11 = m.losujgold(); Sleep(1000); //przypisanie do zmiennej ilo�ci zlota
	cout << "EXP: " << m1 << endl;
	cout << "Z�oto: " << m11 << endl << endl;

	//-----------losowanie exp i gold misja 2
	cout << "[2]" << endl;
	m2 = m.losujdos(); Sleep(1000);
	m22 = m.losujgold();Sleep(1000);
	cout << "EXP: " << m2 << endl;
	cout << "Z�oto: " << m22 << endl << endl;

	//-----------losowanie exp i gold misja 3
	cout << "[3]" << endl;
	m3 = m.losujdos(); Sleep(1000);
	m33 = m.losujgold();
	cout << "EXP: " << m3 << endl;
	cout << "Z�oto: " << m33 << endl << endl;

	//-------------------------------------------
	cout << "[4]" << " Powr�t do menu" << endl << endl;

	for (int i = 0; i < 80; i++) cout << "_"; // odzielenie kresk�

	if (g.getliczbazadan() == 0) {
		cout << endl << "Uko�czono dost�pne misje! Zakup pakiet misji z gabinetu magii.";
		Sleep(2000);
		system("cls");
		return;
	}
	
	cout << endl << endl << "Wybieram misj� nr: "; cin >> misjaswitch;
	
		switch (misjaswitch)
		{
		case 1:
			m.ladowanie(); //metoda ukazuje animacj� i odejmuje liczb� misji mo�liwych do wykonania
			g.dodajdoswiadczenie(m1); //metoda dodaje do�wiadczenie
			g.dodajzloto(m11); //metoda dodaje z�oto
			cout << endl << "Misja uko�czona!" << endl << "Zdobyty EXP: " << m1 << " Zdobyte z�oto: " << m11; //wypisanie
			g.odejmijliczbazadan(); //odjecie 1 od liczby zadan
			Sleep(3000); //3 sec pauza
			system("cls"); //wyczyszczenie konsoli
			break; //powr�t do menu misji
		case 2:
			m.ladowanie();
			g.dodajdoswiadczenie(m2);
			g.dodajzloto(m22);
			cout << endl << "Misja uko�czona!" << endl << "Zdobyty EXP: " << m2 << " Zdobyte z�oto: " << m22;
			g.odejmijliczbazadan();
			Sleep(3000);
			system("cls");
			break;
		case 3:
			m.ladowanie();
			g.dodajdoswiadczenie(m3);
			g.dodajzloto(m33);
			cout << endl << "Misja uko�czona!" << endl << "Zdobyty EXP: " << m3 << " Zdobyte z�oto: " << m33;
			g.odejmijliczbazadan();
			Sleep(3000);
			system("cls");
			break;
		case 4:
			system("cls");
			break;
		default:
				system("cls");
				break;
		}
	} while (misjaswitch<=3);
}