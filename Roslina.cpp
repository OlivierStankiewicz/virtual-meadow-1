#include "Roslina.h"
#include <cstdlib>
#include "constants.h"

Roslina::Roslina(int sila, int pozX, int pozY, Swiat& swiat, char reprezentacja)
	:Organizm(sila, 0, pozX, pozY, swiat, reprezentacja, GREEN)
{}

void Roslina::akcja()
{
	if (wiek)
	{
		float random = (float)rand() / RAND_MAX;

		if (random < RNG_ROZSIANIA)
			rozmnazanie(this);
	}

	starzejSie();
}

Roslina::~Roslina()
{}
