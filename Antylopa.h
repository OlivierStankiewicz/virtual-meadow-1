#pragma once
#include "Zwierze.h"
class Antylopa : public Zwierze
{
public:
	Antylopa(int pozX, int pozY, Swiat& swiat);
	virtual Organizm* stworzOrganizm(int pozX, int pozY) override;
	virtual string typToString() override { return "Antylopa"; }
	virtual void akcja() override;
	virtual int specjalnaUmiejetnosc(Organizm* atakujacy) override;
	~Antylopa();
};

