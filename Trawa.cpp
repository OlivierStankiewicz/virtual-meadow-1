#include "Trawa.h"
#include "constants.h"

Trawa::Trawa(int pozX, int pozY, Swiat& swiat)
	:Roslina(0, pozX, pozY, swiat, REPREZENTACJA_TRAWY)
{}

Organizm* Trawa::stworzOrganizm(int pozX, int pozY)
{
	return new Trawa(pozX, pozY, swiat);
}

Trawa::~Trawa()
{}