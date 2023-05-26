#include "Guarana.h"
#include "constants.h"

Guarana::Guarana(int pozX, int pozY, Swiat& swiat)
	:Roslina(0, pozX, pozY, swiat, REPREZENTACJA_GUARANY)
{}

Organizm* Guarana::stworzOrganizm(int pozX, int pozY)
{
	return new Guarana(pozX, pozY, swiat);
}

int Guarana::specjalnaUmiejetnosc(Organizm* atakujacy)
{
	swiat.komentator.oglosZabicie(atakujacy, this);
	atakujacy->zwiekszSile(3);
	swiat.komentator.oglosZwiekszenieSily(atakujacy, 3);
	delete this;
	return 2;
}

Guarana::~Guarana()
{}