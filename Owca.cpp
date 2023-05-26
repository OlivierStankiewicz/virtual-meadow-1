#include "Owca.h"
#include "constants.h"

Owca::Owca(int pozX, int pozY, Swiat& swiat)
	:Zwierze(4, 4, pozX, pozY, swiat, REPREZENTACJA_OWCY)
{}

Organizm* Owca::stworzOrganizm(int pozX, int pozY)
{
	return new Owca(pozX, pozY, swiat);
}

Owca::~Owca()
{}