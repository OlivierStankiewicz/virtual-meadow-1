#pragma once
#include "Zwierze.h"
class Wilk : public Zwierze
{
public:
	Wilk(int pozX, int pozY, Swiat& swiat);
	virtual Organizm* stworzOrganizm(int pozX, int pozY) override;
	virtual string typToString() override { return "Wilk"; }
	~Wilk();
};

