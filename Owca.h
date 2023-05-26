#pragma once
#include "Zwierze.h"
class Owca : public Zwierze
{
public:
	Owca(int pozX, int pozY, Swiat& swiat);
	virtual Organizm* stworzOrganizm(int pozX, int pozY) override;
	virtual string typToString() override { return "Owca"; }
	~Owca();
};

