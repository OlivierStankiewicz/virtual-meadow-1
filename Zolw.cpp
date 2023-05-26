#include "Zolw.h"
#include "constants.h"

Zolw::Zolw(int pozX, int pozY, Swiat& swiat)
	:Zwierze(2, 1, pozX, pozY, swiat, REPREZENTACJA_ZOLWIA)
{}

Organizm* Zolw::stworzOrganizm(int pozX, int pozY)
{
	return new Zolw(pozX, pozY, swiat);
}

void Zolw::akcja()
{
	bool czyIstnieje = true;

	float random = (float)rand() / RAND_MAX;

	if (random < RNG_RUCHU_ZOLWIA && wiek)
	{
		int newX = pozX, newY = pozY;
		int ruch = wylosujRuch(false);
		switch (ruch)
		{
		case 0:
			newX++;
			break;
		case 1:
			newX--;
			break;
		case 2:
			newY++;
			break;
		case 3:
			newY--;
			break;
		}

		Organizm* other = swiat.ktoNaPolu(newX, newY);
		if ((other  && kolizja(other, czyIstnieje)) || !other)
		{
			pozX = newX;
			pozY = newY;
		}
	}

	if (czyIstnieje)
		starzejSie();
}

int Zolw::specjalnaUmiejetnosc(Organizm* atakujacy)
{
	if (atakujacy->getSila() < 5)
	{
		swiat.komentator.oglosOdbicieAtaku(this, atakujacy);
		return 1;
	}

	return 0;
}

Zolw::~Zolw()
{}