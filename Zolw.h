#pragma once
#include "Zwierze.h"
class Zolw : public Zwierze
{
public:
	Zolw(int pozX, int pozY, Swiat& swiat);
	virtual Organizm* stworzOrganizm(int pozX, int pozY) override;
	virtual string typToString() override { return "Zolw"; }
	virtual void akcja() override;
	virtual int specjalnaUmiejetnosc(Organizm* atakujacy) override;
	~Zolw();
};

