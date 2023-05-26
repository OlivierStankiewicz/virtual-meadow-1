#pragma once
#include "Zwierze.h"
class Czlowiek : public Zwierze
{
public:
	Czlowiek(int pozX, int pozY, Swiat& swiat);
	virtual Organizm* stworzOrganizm(int pozX, int pozY) override;
	virtual string typToString() override { return "Czlowiek"; }
	virtual void akcja() override;
	virtual string zapisOrganizmu() override;
	void setUmiejLicz(int licznik);
	void setUmiejWlacz(bool wlaczona);
	~Czlowiek();

	int getUmiejLicz() { return umiejetnoscLicznik;  }
	bool getUmiejWlacz() { return umiejetnoscWlaczona; }

private:
	int umiejetnoscLicznik;
	bool umiejetnoscWlaczona;
};

