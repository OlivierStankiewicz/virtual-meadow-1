#pragma once
#include "Roslina.h"
class WilczeJagody : public Roslina
{
public:
	WilczeJagody(int pozX, int pozY, Swiat& swiat);
	virtual Organizm* stworzOrganizm(int pozX, int pozY) override;
	virtual string typToString() override { return "Wilcze Jagody"; }
	virtual int specjalnaUmiejetnosc(Organizm* atakujacy) override;
	~WilczeJagody();
};
