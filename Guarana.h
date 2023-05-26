#pragma once
#include "Roslina.h"
class Guarana : public Roslina
{
public:
	Guarana(int pozX, int pozY, Swiat& swiat);
	virtual Organizm* stworzOrganizm(int pozX, int pozY) override;
	virtual string typToString() override { return "Guarana"; }
	virtual int specjalnaUmiejetnosc(Organizm* atakujacy) override;
	~Guarana();
};
