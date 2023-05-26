#pragma once
#include "Roslina.h"
class BarszczSosnowskiego : public Roslina
{
public:
	BarszczSosnowskiego(int pozX, int pozY, Swiat& swiat);
	virtual Organizm* stworzOrganizm(int pozX, int pozY) override;
	virtual string typToString() override { return "Barszcz Sosnowskiego"; }
	virtual int specjalnaUmiejetnosc(Organizm* atakujacy) override;
	virtual void akcja() override;
	~BarszczSosnowskiego();
};
