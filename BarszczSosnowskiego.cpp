#include "BarszczSosnowskiego.h"
#include "constants.h"

BarszczSosnowskiego::BarszczSosnowskiego(int pozX, int pozY, Swiat& swiat)
	:Roslina(10, pozX, pozY, swiat, REPREZENTACJA_BARSZCZU_SOSNOWSKIEGO)
{}

Organizm* BarszczSosnowskiego::stworzOrganizm(int pozX, int pozY)
{
	return new BarszczSosnowskiego(pozX, pozY, swiat);
}

int BarszczSosnowskiego::specjalnaUmiejetnosc(Organizm* atakujacy)
{
	swiat.komentator.oglosZabicie(atakujacy, this);
	swiat.komentator.oglosZatrucie(atakujacy, this);
	delete atakujacy;
	delete this;
	return 3;
}

void BarszczSosnowskiego::akcja()
{
	if (wiek)
	{
		float random = (float)rand() / RAND_MAX;

		if (random < RNG_ROZSIANIA)
			rozmnazanie(this);

		Organizm* o1 = swiat.ktoNaPolu(pozX + 1, pozY);
		Organizm* o2 = swiat.ktoNaPolu(pozX - 1, pozY);
		Organizm* o3 = swiat.ktoNaPolu(pozX, pozY + 1);
		Organizm* o4 = swiat.ktoNaPolu(pozX, pozY - 1);
		Organizm* tab[4] = { o1, o2, o3, o4 };

		for (int i = 0; i < 4; i++)
		{
			if (tab[i] && tab[i]->getInicjatywa())
			{
				swiat.komentator.oglosZabicie(this, tab[i]);
				delete tab[i];
			}
		}
	}

	starzejSie();
}

BarszczSosnowskiego::~BarszczSosnowskiego()
{}
