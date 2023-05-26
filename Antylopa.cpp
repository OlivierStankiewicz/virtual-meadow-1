#include "Antylopa.h"
#include "constants.h"

Antylopa::Antylopa(int pozX, int pozY, Swiat& swiat)
	:Zwierze(4, 4, pozX, pozY, swiat, REPREZENTACJA_ANTYLOPY)
{}

Organizm* Antylopa::stworzOrganizm(int pozX, int pozY)
{
	return new Antylopa(pozX, pozY, swiat);
}

void Antylopa::akcja()
{
	bool czyIstnieje = true;

	int i = 0;
	while (czyIstnieje && wiek && i < 2)
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
		if ((other && kolizja(other, czyIstnieje)) || !other)
		{
			pozX = newX;
			pozY = newY;
		}
		i++;
	}

	if (czyIstnieje)
		starzejSie();
}

int Antylopa::specjalnaUmiejetnosc(Organizm* atakujacy)
{
	float random = (float)rand() / RAND_MAX;

	if (random < RNG_UCIECZKI_ANTYLOPY && !czyOtoczony())
	{
		swiat.komentator.oglosUcieczke(this, atakujacy);
		int ruch = wylosujRuch(true);
		switch (ruch)
		{
		case 0:
			pozX++;
			break;
		case 1:
			pozX--;
			break;
		case 2:
			pozY++;
			break;
		case 3:
			pozY--;
			break;
		}
		return 2;
	}

	return 0;
}

Antylopa::~Antylopa()
{}