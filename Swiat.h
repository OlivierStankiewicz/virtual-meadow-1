#pragma once
#include "Komentator.h"

class Organizm;

class Swiat
{
public:
	Swiat();
	Swiat(int sizeX, int sizeY);
	Swiat(int sizeX, int sizeY, float zapelnienie);

	void wykonajTure();
	void rysujSwiat();
	
	int getSizeX() { return sizeX; }
	int getSizeY() { return sizeY; }
	bool getKoniecSwiata() { return koniecSwiata; }

	void addOrganizm(Organizm* organizm);
	void removeOrganizm(Organizm* organizm);
	Organizm* ktoNaPolu(int x, int y);
	Komentator komentator;
	void zakonczSwiat() { koniecSwiata = true; }
	void chceZapisac() { czyZapis = true; }
	bool wczytajSwiat();
	void generujOrganizmy(float zapelnienie);
	~Swiat();

private:
	void rysujMape();
	void rysujMenu();

	void zapiszStanGry();
	
	void losujWolnePole(int& x, int& y);

	int sizeX, sizeY;
	Organizm** organizmy;
	char*** mapa;
	void aktualizujMape();
	void sortujOrganizmy();
	bool czyAWazniejszyOdB(Organizm* a, Organizm* b);
	bool koniecSwiata;
	bool czyZapis;
};

