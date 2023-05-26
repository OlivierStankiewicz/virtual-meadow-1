#include "Swiat.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleTitleA("| Wirtualna Laka        193454 |");
	char input;
	Swiat* swiat;

	while (true)
	{
		system("cls");
		cout << "Wirtualna Laka - gra autorstwa Olivier Stankiewicz 193454" << endl;
		cout << "Nowa gra - N    Wczytaj gre - W    Wyjscie - Q" << endl;
		cout << "Wybor: ";
		cin >> input;
		int szerokosc, wysokosc;
		
		if (input == 'q' || input == 'Q')
			return 0;
		
		if(input=='n' || input=='N')
		{
			float zapelnienie;
			cout << "Podaj szerokosc laki: ";
			cin >> szerokosc;
			cout << "Podaj wysokosc laki: ";
			cin >> wysokosc;
			while (true)
			{
				cout << "Podaj wspolczynnik zapelnienia laki [0-1]: ";
				cin >> zapelnienie;
				if (zapelnienie >= 0 && zapelnienie < 1)
					break;
			}
			
			swiat = new Swiat(szerokosc, wysokosc, zapelnienie);
			break;
		}

		if (input == 'w' || input == 'W')
		{
			swiat = new Swiat();
			if (swiat->wczytajSwiat())
			{
				swiat->rysujSwiat();
				break;
			}
		}
	}

	while(input!='q' && input != 'Q' && !swiat->getKoniecSwiata())
	{
		swiat->wykonajTure();
		swiat->rysujSwiat();
	}

	cout << "KONIEC GRY" << endl;

	return 0;
}