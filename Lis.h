#pragma once
#include "Zwierze.h"
class Lis : public Zwierze
{
public:
	Lis(int pozX, int pozY, Swiat& swiat);
	virtual Organizm* stworzOrganizm(int pozX, int pozY) override;
	virtual string typToString() override { return "Lis"; }
	virtual void akcja() override;
	~Lis();
};

