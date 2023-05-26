#include "Mlecz.h"
#include <cstdlib>
#include "constants.h"

Mlecz::Mlecz(int pozX, int pozY, Swiat& swiat)
	:Roslina(0, pozX, pozY, swiat, REPREZENTACJA_MLECZA)
{}

Organizm* Mlecz::stworzOrganizm(int pozX, int pozY)
{
	return new Mlecz(pozX, pozY, swiat);
}

void Mlecz::akcja()
{
	if (wiek)
	{
		for (int i = 0; i < 3; i++)
		{
			float random = (float)rand() / RAND_MAX;

			if (random < RNG_ROZSIANIA)
				rozmnazanie(this);
		}
	}

	starzejSie();
}

Mlecz::~Mlecz()
{}