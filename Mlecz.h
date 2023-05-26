#pragma once
#include "Roslina.h"
class Mlecz : public Roslina
{
public:
	Mlecz(int pozX, int pozY, Swiat& swiat);
	virtual Organizm* stworzOrganizm(int pozX, int pozY) override;
	virtual string typToString() override { return "Mlecz"; }
	virtual void akcja() override;
	~Mlecz();
};
