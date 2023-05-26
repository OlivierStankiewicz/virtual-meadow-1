#pragma once
#include "Organizm.h"
#include "Swiat.h"
#include "constants.h"

class Roslina : public Organizm
{
public:
	Roslina(int sila, int pozX, int pozY, Swiat& swiat, char reprezentacja);
	virtual void akcja() override;
	virtual int kolizja(Organizm* other, bool& istnieje) override { return 0; }
	~Roslina();
};
