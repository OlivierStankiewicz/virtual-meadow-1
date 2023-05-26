#pragma once
#include <iostream>
#include <string>
#include "constants.h"
using namespace std;

class Organizm;

class Czlowiek;

class Komentator
{
public:
	Komentator();
	void oglosZabicie(Organizm* kto, Organizm* kogo);
	void oglosZwiekszenieSily(Organizm* kto, int oIle);
	void oglosZatrucie(Organizm* kto, Organizm* kim);
	void oglosRozmnozenie(Organizm* a, Organizm* b);
	void oglosOdbicieAtaku(Organizm* kto, Organizm* czyj);
	void oglosUcieczke(Organizm* kto, Organizm* przedKim);
	void oglosUmiejetnoscCzlowieka(Czlowiek* uzytkownik);
	void oglosSpalenie(Organizm* kto, Organizm* kogo);
	void skomentujChecZapisu();
	void skomentujStanUmiejetnosci();
	void skomentujTure();
	string getKomentarz(int ktory);
	string getOUmiejetnosci() { return oUmiejetnosci; }
	void addKomentarz(string komentarz);
	void setOUmiejetnosci(string komentarz);
	~Komentator();

private:
	string komentarze[LIMIT_KOMENTARZY];
	string oUmiejetnosci;
};

