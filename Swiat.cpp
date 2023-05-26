#include "Swiat.h"
#include "Organizm.h"
#include <iostream>
#include <cstdlib>
#include "constants.h"
#include <Windows.h>
#include <string>
#include <fstream>
#include <conio.h>

#include "Zwierze.h"
#include "Owca.h"
#include "Wilk.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "BarszczSosnowskiego.h"
#include "Czlowiek.h"

using namespace std;

Swiat::Swiat()
	:Swiat(0, 0)
{}

Swiat::Swiat(int sizeX, int sizeY)
	:sizeX(sizeX), sizeY(sizeY), komentator(), koniecSwiata(false), czyZapis(false)
{
	srand(time(NULL));
	this->mapa = new char** [sizeX];
	for (int i = 0; i < sizeX; i++)
	{
		mapa[i] = new char* [sizeY];
		for (int j = 0; j < sizeY;	j++)
		{
			mapa[i][j] = new char[2];
			mapa[i][j][0] = emptySquare;
			mapa[i][j][0] = WHITE;

		}
	}

	this->organizmy = new Organizm * [sizeX * sizeY];
	for (int i = 0; i < sizeX*sizeY; i++)
	{
		this->organizmy[i] = NULL;
	}
}

Swiat::Swiat(int sizeX, int sizeY, float zapelnienie)
	:Swiat(sizeX, sizeY)
{
	generujOrganizmy(zapelnienie);
}

void Swiat::aktualizujMape()
{
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			mapa[i][j][0] = emptySquare;
			mapa[i][j][1] = WHITE;
		}
	}

	for (int i = 0; i < sizeX * sizeY; i++)
	{
		if (organizmy[i] != NULL)
		{
			int x = organizmy[i]->getX();
			int y = organizmy[i]->getY();
			mapa[x][y][0] = organizmy[i]->getReprezentacja();
			mapa[x][y][1] = organizmy[i]->getKolor();
		}
	}
}

void Swiat::rysujSwiat()
{
	system("cls");
	rysujMenu();
	komentator.skomentujStanUmiejetnosci();
	rysujMape();
	cout << endl;
	komentator.skomentujTure();
}

void Swiat::rysujMape()
{
	this->aktualizujMape();

	HANDLE baseColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(baseColor, WHITE);

	cout << boardTopLeft;
	for (int i = 0; i < sizeX*2+1; i++)
		cout << boardHorizontal;
	cout << boardTopRight << endl;

	for (int i = 0; i < sizeY; i++)
	{
		cout << boardVertical << " ";
		for (int j = 0; j < sizeX; j++)
		{
			SetConsoleTextAttribute(baseColor, (int)mapa[j][i][1]);
			cout << mapa[j][i][0] << " ";
		}
		SetConsoleTextAttribute(baseColor, WHITE);
		cout << boardVertical << endl;
	}

	cout << boardBottomLeft;
	for (int i = 0; i < sizeX * 2 + 1; i++)
		cout << boardHorizontal;
	cout << boardBottomRight << endl;
}

void Swiat::addOrganizm(Organizm* organizm)
{
	for (int i = 0; i < sizeX * sizeY; i++)
	{
		if (organizmy[i] == NULL)
		{
			organizmy[i] = organizm;
			break;
		}
	}
}

void Swiat::removeOrganizm(Organizm* organizm)
{
	for (int i = 0; i < sizeX * sizeY; i++)
	{
		if (organizmy[i] == organizm)
		{
			organizmy[i] = NULL;
			break;
		}
	}
}

Organizm* Swiat::ktoNaPolu(int x, int y)
{
	for (int i = 0; i < sizeX * sizeY; i++)
	{
		if (organizmy[i] != NULL && organizmy[i]->getX() == x && organizmy[i]->getY() == y)
		{
			return organizmy[i];
		}
	}
	return NULL;
}

void Swiat::wykonajTure()
{
	sortujOrganizmy();

	for (int i = 0; i < sizeX * sizeY; i++)
	{
		if (organizmy[i] != NULL)
		{
			organizmy[i]->akcja();
		}
	}

	if (czyZapis)
	{
		zapiszStanGry();
		czyZapis = false;
	}
}

void Swiat::sortujOrganizmy()
{
	int gap = 1;
	while (gap <= sizeX*sizeY) {
		gap <<= 1;
	}
	gap -= gap>>1;

	while (gap >= 1)
	{
		for (int i = gap; i < sizeX * sizeY; i++)
		{
			Organizm* x = organizmy[i];
			int j = i;
			while (j >= gap && czyAWazniejszyOdB(x, organizmy[j - gap]))
			{
				organizmy[j] = organizmy[j - gap];
				j -= gap;

			}
			organizmy[j] = x;

		}
		gap = gap / 2;
	}
}

bool Swiat::czyAWazniejszyOdB(Organizm* a, Organizm* b)
{
	if (a == NULL)
		return false;

	if (a != NULL && b == NULL)
		return true;

	int iniA = a->getInicjatywa();
	int iniB = b->getInicjatywa();

	if (iniA > iniB)
		return true;

	if (iniA == iniB && a->getWiek() > a->getWiek())
		return true;

	return false;
}

void Swiat::rysujMenu()
{
	cout << "Wirtualna Laka - gra autorstwa Olivier Stankiewicz 193454" << endl;
	cout << "Ruch - Strzalki    Specjalna umiejetnosc - Spacja    Zakonczenie gry - Q    Zapisz gre - Z" << endl;
}

void Swiat::generujOrganizmy(float zapelnienie)
{
	int x, y;
	losujWolnePole(x, y);
	new Czlowiek(x, y, *this);
	for (int i = 0; i < sizeX * sizeY-1; i++)
	{
		float random = (float)rand() / RAND_MAX;

		if (random < zapelnienie)
		{
			int jaki = rand() % LICZBA_ORGANIZMOW;
			losujWolnePole(x, y);

			switch (jaki)
			{
			case 0:
				new Wilk(x, y, *this);
				break;
			case 1:
				new Owca(x, y, *this);
				break;
			case 2:
				new Lis(x, y, *this);
				break;
			case 3:
				new Zolw(x, y, *this);
				break;
			case 4:
				new Antylopa(x, y, *this);
				break;
			case 5:
				new Trawa(x, y, *this);
				break;
			case 6:
				new Mlecz(x, y, *this);
				break;
			case 7:
				new Guarana(x, y, *this);
				break;
			case 8:
				new WilczeJagody(x, y, *this);
				break;
			case 9:
				new BarszczSosnowskiego(x, y, *this);
				break;

			}
		}
	}
}

void Swiat::losujWolnePole(int& x, int& y)
{
	while (true)
	{
		x = rand() % sizeX;
		y = rand() % sizeY;

		if (!ktoNaPolu(x, y))
			return;
	}
}

void Swiat::zapiszStanGry()
{
	string fileName;
	system("cls");
	cout << "Nazwa pliku w ktorym chcesz zapisac: ";
	cin >> fileName;
	ofstream plik(fileName);
	if (plik.is_open())
	{
		plik << "Swiat" << endl;
		plik << sizeX << " " << sizeY << " " << koniecSwiata << endl;
		plik << endl;
		plik << "Komentarze" << endl;
		plik << komentator.getOUmiejetnosci() << endl;
		for (int i = 0; i < LIMIT_KOMENTARZY; i++)
		{
			string komentarz = komentator.getKomentarz(i);
			if (komentarz != "")
				plik << komentarz << endl;
		}
		plik << endl;
		plik << "Organizmy" << endl;
		for (int i = 0; i < sizeX * sizeY; i++)
		{
			if (organizmy[i])
				plik << organizmy[i]->zapisOrganizmu() << endl;
		}
		plik << "0";
		plik.close();
		cout << "Zapisano pomyslnie!" << endl;
	}
	else
		cout << "Nie udalo sie zapisac" << endl;

	cout << "Wcisnij dowolny klawisz by kontynuowac" << endl;
	_getch();
	system("cls");
}

bool Swiat::wczytajSwiat()
{
	string fileName;
	system("cls");
	cout << "Nazwa pliku z ktorego chcesz wczytac: ";
	cin >> fileName;
	ifstream plik(fileName);
	if (plik.is_open())
	{
		string text;
		plik >> text;

		int num;
		plik >> num;
		sizeX = num;
		plik >> num;
		sizeY = num;
		plik >> num;
		if (num)
			zakonczSwiat();
		
		this->mapa = new char** [sizeX];
		for (int i = 0; i < sizeX; i++)
		{
			mapa[i] = new char* [sizeY];
			for (int j = 0; j < sizeY; j++)
			{
				mapa[i][j] = new char[2];
				mapa[i][j][0] = emptySquare;
				mapa[i][j][0] = WHITE;

			}
		}

		this->organizmy = new Organizm * [sizeX * sizeY];
		for (int i = 0; i < sizeX * sizeY; i++)
		{
			this->organizmy[i] = NULL;
		}

		getline(plik, text);
		getline(plik, text);
		getline(plik, text);

		getline(plik, text);
		komentator.setOUmiejetnosci(text);
		while (true)
		{
			getline(plik, text);
			if (text == "")
				break;
			komentator.addKomentarz(text);
		}

		getline(plik, text);

		int reprezentacja, pozX, pozY, sila, wiek;

		while (true)
		{
			plik >> reprezentacja;
			if (!reprezentacja)
				break;
			plik >> pozX;
			plik >> pozY;
			plik >> sila;
			plik >> wiek;

			Organizm* o;
			Czlowiek* c;
			switch (reprezentacja)
			{
			case REPREZENTACJA_CZLOWIEKA:
				c = new Czlowiek(pozX, pozY, *this);
				o = c;
				o->setSila(sila);
				o->setWiek(wiek);
				plik >> num;
				if (num)
					c->setUmiejWlacz(true);
				plik >> num;
				c->setUmiejLicz(num);
				break;

			case REPREZENTACJA_WILKA:
				o = new Wilk(pozX, pozY, *this);
				o->setSila(sila);
				o->setWiek(wiek);
				break;

			case REPREZENTACJA_OWCY:
				o = new Owca(pozX, pozY, *this);
				o->setSila(sila);
				o->setWiek(wiek);
				break;

			case REPREZENTACJA_LISA:
				o = new Lis(pozX, pozY, *this);
				o->setSila(sila);
				o->setWiek(wiek);
				break;

			case REPREZENTACJA_ZOLWIA:
				o = new Zolw(pozX, pozY, *this);
				o->setSila(sila);
				o->setWiek(wiek);
				break;

			case REPREZENTACJA_ANTYLOPY:
				o = new Antylopa(pozX, pozY, *this);
				o->setSila(sila);
				o->setWiek(wiek);
				break;

			case REPREZENTACJA_TRAWY:
				o = new Trawa(pozX, pozY, *this);
				o->setSila(sila);
				o->setWiek(wiek);
				break;

			case REPREZENTACJA_MLECZA:
				o = new Mlecz(pozX, pozY, *this);
				o->setSila(sila);
				o->setWiek(wiek);
				break;

			case REPREZENTACJA_GUARANY:
				o = new Guarana(pozX, pozY, *this);
				o->setSila(sila);
				o->setWiek(wiek);
				break;

			case REPREZENTACJA_WILCZYCH_JAGOD:
			o = new WilczeJagody(pozX, pozY, *this);
			o->setSila(sila);
			o->setWiek(wiek);
			break;

			case REPREZENTACJA_BARSZCZU_SOSNOWSKIEGO:
				o = new BarszczSosnowskiego(pozX, pozY, *this);
				o->setSila(sila);
				o->setWiek(wiek);
				break;
			}
		}
		

		cout << "Wczytano pomyslnie!" << endl;
		cout << "Wcisnij dowolny klawisz by kontynuowac" << endl;
		aktualizujMape();
		_getch();
		return true;
	}
	
	cout << "Nie udalo sie wczytac";
	cout << "Wcisnij dowolny klawisz by kontynuowac" << endl;
	_getch();
	return false;
}

Swiat::~Swiat()
{
	for (int i = 0; i < sizeX * sizeY; i++)
	{
		if (organizmy[i] != NULL)
		{
			delete organizmy[i];
		}
	}
	delete[] organizmy;

	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
			delete[] mapa[i][j];

		delete[] mapa[i];
	}
	delete[] mapa;
}