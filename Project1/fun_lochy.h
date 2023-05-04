#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <clocale>
#include <time.h>
#include <stdlib.h>
using namespace std;

void lochy(Gracz& g, Lochy& l, Potwory& p)
{
	int loch;
	do
	{
		system("cls");
		cout << "LOCHY" << endl;
		for (int i = 0; i < 80; i++) cout << "_"; // odzielenie kresk¹
		cout << endl << "SI£A: " << g.getsila() << " | "; //wyœwietlenie si³y w menu
		cout << "¯YCIE: " << "[" << g.getzycie() << "/" << g.getmaxzycie() << "]" << endl; //wyœwietlenie % szczescia w menu
		cout << endl << "Loch: " << l.getNrLochu() << " " << " Potwór: " << l.getNrPotwora();
		cout << endl << endl << "[1] Zaatakuj potwora.";
		cout << endl << "[2] WyjdŸ z lochów.";
		cout << endl << endl << "Wybieram: ";
		cin >> loch;
		switch (loch)
		{
		case 1:
			if (g.getzycie() > 0)
			{
				g.walka(p.getsila(), p.getzycie());
				if (g.getzycie() > 0)
				{
					l.setNrPotwora(); //zmiana nr potwora po wygranej
					l.setNrLochu(); //zmiana nr lochu po wygranej
					p.setsila(l.getNrLochu(), l.getNrPotwora()); //ustawienie sily nowego potwora
					p.setzycie(l.getNrLochu(), l.getNrPotwora()); //ustawienie zycia nowego potwora
				}
				system("cls");
				menu(g, l);
			}
			else { cout << "Potrzebujesz wskrzeszenia!"; menu(g, l); }
		case 2:
			system("cls");
			break;
		}
	} while (loch==1);
}