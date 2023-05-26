#pragma once
#include "Swiat.h"
#include "Komentator.h"
#include <string>
using namespace std;

class Organizm
{
public:
	Organizm(int sila, int inicjatywa, int pozX, int pozY, Swiat& swiat, char reprezentacja, char kolor);

	virtual void akcja() = 0;
	virtual int kolizja(Organizm* other, bool& istnieje) = 0;

	int getX() { return pozX; }
	int getY() { return pozY; }
	char getReprezentacja() { return reprezentacja; }
	int getInicjatywa() { return inicjatywa; }
	int getWiek() { return wiek; }
	int getSila() { return sila; }
	char getKolor() { return kolor; }

	void setSila(int nowaSila);
	void setWiek(int nowyWiek);

	void zwiekszSile(int oIle) { sila += oIle; }
	string organizmToString();
	virtual string typToString() = 0;
	virtual int specjalnaUmiejetnosc(Organizm* atakujacy) { return 0; } // 0-brak, 1-jest ale bez ruchu, 2-jest i ruch
	virtual string zapisOrganizmu();

	virtual ~Organizm();

protected:
	int sila, inicjatywa, pozX, pozY, wiek;
	Swiat& swiat;
	char reprezentacja, kolor;

	void starzejSie() { wiek++; }
	void rozmnazanie(Organizm* other);
	int wylosujRuch(bool musiBycWolne);
	bool czyOtoczony();
	virtual Organizm* stworzOrganizm(int pozX, int pozY) = 0;
};