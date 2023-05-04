#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <clocale>
#include <time.h>
#include <stdlib.h>
using namespace std;

#pragma warning(disable : 4996) //ignorowanie 'b³êdu' przy getch() przy kompilacji
void ekwipunek(Gracz& g, Lochy& l)
{
	system("cls");
	cout << "EKWIPUNEK" << endl;
	for (int i = 0; i < 80; i++) cout << "_"; // odzielenie kresk¹
	cout << endl << "HE£M";
	if (g.gethelm() == 0) cout << " (brak)"; else cout << " +" << g.gethelm() << " ¿ycia";
	cout << endl << "ZBROJA";
	if (g.getzbroja() == 0) cout << " (brak)"; else cout << " +" << g.getzbroja() << " ¿ycia";
	cout << endl << "MIECZ";
	if (g.getmiecz() == 0) cout << " (brak)"; else cout << " +" << g.getmiecz() << " si³y";
	cout << endl << "TARCZA";
	if (g.gettarcza() == 0) cout << " (brak)"; else cout << " +" << g.gettarcza() << " szczêœcia" << endl << endl;
	cout << endl << endl << "[WCIŒNIJ DOWOLNY PRZYCISK ABY WRÓCIÆ DO MENU]";
	if (getch()) { //oczekiwanie na wcisniecie klawisza
		system("cls");
	}
	return;
}