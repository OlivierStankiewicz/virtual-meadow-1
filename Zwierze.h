#pragma once
#include "Organizm.h"
#include "Swiat.h"
class Zwierze : public Organizm
{
public:
	Zwierze(int sila, int inicjatywa, int pozX, int pozY, Swiat& swiat, char reprezentacja);
	Zwierze(int sila, int inicjatywa, int pozX, int pozY, Swiat& swiat, char reprezentacja, char kolor);
	virtual void akcja() override;
	virtual int kolizja(Organizm* other, bool& istnieje) override;  // 1 - ruch 0 - bez ruchu
	virtual ~Zwierze();

protected:
	int specjalnaWalka(Organizm* atakowany); // 0-brak, 1-jest ale bez ruchu, 2-jest i ruch, 3 smierc atakujacego
	bool walkaWygrana(Organizm* atakowany);
};

