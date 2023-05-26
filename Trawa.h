#pragma once
#include "Roslina.h"
class Trawa : public Roslina
{
public:
	Trawa(int pozX, int pozY, Swiat& swiat);
	virtual Organizm* stworzOrganizm(int pozX, int pozY) override;
	virtual string typToString() override { return "Trawa"; }
	~Trawa();
};
