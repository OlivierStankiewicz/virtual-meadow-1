#include "Wilk.h"
#include "constants.h"

Wilk::Wilk(int pozX, int pozY, Swiat& swiat)
	:Zwierze(9, 5, pozX, pozY, swiat, REPREZENTACJA_WILKA)
{}

Organizm* Wilk::stworzOrganizm(int pozX, int pozY)
{
	return new Wilk(pozX, pozY, swiat);
}

Wilk::~Wilk()
{}