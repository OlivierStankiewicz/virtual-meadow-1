#include "Czlowiek.h"
#include "constants.h"
#include <conio.h>
#include <iostream>
using namespace std;

Czlowiek::Czlowiek(int pozX, int pozY, Swiat& swiat)
	:Zwierze(5, 4, pozX, pozY, swiat, REPREZENTACJA_CZLOWIEKA, LIGHT_AQUA)
{
	umiejetnoscLicznik = 5;
	umiejetnoscWlaczona = false;
}

void Czlowiek::setUmiejLicz(int licznik)
{
	umiejetnoscLicznik = licznik;
}

void Czlowiek::setUmiejWlacz(bool wlaczona)
{
	umiejetnoscWlaczona = wlaczona;
}

Organizm* Czlowiek::stworzOrganizm(int pozX, int pozY)
{
	return new Czlowiek(pozX, pozY, swiat);
}

void Czlowiek::akcja()
{
	bool czyIstnieje = true;
	if (wiek)
	{
		int input = _getch();

		int newX = pozX, newY = pozY;
		
		while (true)
		{
			if (input == ' ' && !umiejetnoscWlaczona && umiejetnoscLicznik == 5)
			{
				umiejetnoscWlaczona = true;
				input = _getch();
			}

			else if (input == 'Z' || input == 'z')
			{
				swiat.chceZapisac();
				swiat.komentator.skomentujChecZapisu();
				input = _getch();
			}
			
			else if (input == 224)
			{
				input = _getch();
				switch (input)
				{
				case ArrowRight:
					newX++;
					break;
				case ArrowLeft:
					newX--;
					break;
				case ArrowDown:
					newY++;
					break;
				case ArrowUp:
					newY--;
					break;
				}
				break;
			}

			else if ( input == 'q' || input == 'Q' )
			{
				swiat.zakonczSwiat();
				break;
			}

			else
				input = _getch();
		}

		if (umiejetnoscWlaczona)
		{
			Organizm* o1 = swiat.ktoNaPolu(pozX + 1, pozY);
			Organizm* o2 = swiat.ktoNaPolu(pozX - 1, pozY);
			Organizm* o3 = swiat.ktoNaPolu(pozX, pozY + 1);
			Organizm* o4 = swiat.ktoNaPolu(pozX, pozY - 1);
			Organizm* tab[4] = { o1, o2, o3, o4 };

			for (int i = 0; i < 4; i++)
			{
				if (tab[i])
				{
					swiat.komentator.oglosSpalenie(this, tab[i]);
					delete tab[i];
				}
			}

			umiejetnoscLicznik--;
			if (umiejetnoscLicznik == 0)
				umiejetnoscWlaczona = false;
		}

		else if (umiejetnoscLicznik < 5)
			umiejetnoscLicznik++;

		if (input != 'q' && input!='Q' && newX >= 0 && newX < swiat.getSizeX() && newY >= 0 && newY < swiat.getSizeY())
		{
			Organizm* other = swiat.ktoNaPolu(newX, newY);
			if ((other && kolizja(other, czyIstnieje)) || !other)
			{
				pozX = newX;
				pozY = newY;
			}
		}
	}

	if (czyIstnieje)
	{
		starzejSie();
		swiat.komentator.oglosUmiejetnoscCzlowieka(this);
	}
}

string Czlowiek::zapisOrganizmu()
{
	string wynik = to_string(reprezentacja) + " ";
	wynik += to_string(pozX) + " ";
	wynik += to_string(pozY) + " ";
	wynik += to_string(sila) + " ";
	wynik += to_string(wiek) + " ";
	wynik += to_string(umiejetnoscWlaczona) + " ";
	wynik += to_string(umiejetnoscLicznik);
	return wynik;
}

Czlowiek::~Czlowiek()
{
	swiat.zakonczSwiat();
}
