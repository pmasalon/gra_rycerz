#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <clocale>
#include <time.h>
#include <stdlib.h>
using namespace std;

void menu(Gracz& g, Lochy& l)
{
	if (g.getzycie() <= 0 && g.getzloto() < 200) //sprawdzenie czy gracz nie jest martwy i jego stanu zlota
	{
		system("cls");
		cout << "PRZEGRA£EŒ!" << endl << "NIE MASZ PIENIÊDZY NA WSKRZESZENIE!";
		cout << endl << "TO KONIEC GRY!";
		Sleep(1500);
		abort();
	}
	if (l.getNrLochu() == 4) //sprawdzenie czy gracz wygral gre
	{
		system("cls");
		cout << "UKOÑCZY£EŒ GRÊ!" << endl << "GRATULACJE!!";
		Sleep(1500);
		abort();
	}
	system("cls");
	cout << "PRZYGODY RYCERZA" << endl;
	cout << "Gracz: " << g.getgracz() << endl; //wypisanie gracza
	for (int i = 0; i < 80; i++) cout << "_"; // odzielenie kresk¹
	cout << endl << "LVL: " << g.getlvl(); //wyœwietlenie lvl w menu
	cout << " [" << g.getdoswiadczenie() << "/100] "; //wyœwietlenie doœwiadczenia w menu
	cout << "Z£OTO: " << g.getzloto() << " | "; //wyœwietlenie zlota w menu
	cout << "SI£A: " << g.getsila() << " | "; //wyœwietlenie si³y w menu
	cout << "¯YCIE: " << "[" << g.getzycie() << "/" << g.getmaxzycie() << "]" << " | "; //wyœwietlenie % szczescia w menu
	cout << "SZCZÊŒCIE: " << g.getszczescie() << "%" << endl; //wyœwietlenie lvl w menu
	for (int i = 0; i < 80; i++) cout << "_"; // odzielenie kresk¹

	cout << endl << "[1] Misje" << endl;
	cout << "[2] Zbrojownia" << endl;
	cout << "[3] Gabinet magii" << endl; //MENU
	cout << "[4] Ekwipunek" << endl;
	cout << "[5] Lochy" << endl;
	cout << "[6] Wyjœcie z gry" << endl;
	cout << endl << endl << "Wybieram: ";
}