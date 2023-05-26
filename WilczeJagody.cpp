#include "WilczeJagody.h"
#include "constants.h"

WilczeJagody::WilczeJagody(int pozX, int pozY, Swiat& swiat)
	:Roslina(99, pozX, pozY, swiat, REPREZENTACJA_WILCZYCH_JAGOD)
{}

Organizm* WilczeJagody::stworzOrganizm(int pozX, int pozY)
{
	return new WilczeJagody(pozX, pozY, swiat);
}

int WilczeJagody::specjalnaUmiejetnosc(Organizm* atakujacy)
{
	swiat.komentator.oglosZabicie(atakujacy, this);
	swiat.komentator.oglosZatrucie(atakujacy, this);
	delete atakujacy;
	delete this;
	return 3;
}

WilczeJagody::~WilczeJagody()
{}