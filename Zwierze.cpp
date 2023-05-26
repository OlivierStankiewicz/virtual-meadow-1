#include "Zwierze.h"
#include "constants.h"

Zwierze::Zwierze(int sila, int inicjatywa, int pozX, int pozY, Swiat& swiat, char reprezentacja)
	:Organizm(sila, inicjatywa, pozX, pozY, swiat, reprezentacja, YELLOW)
{}

Zwierze::Zwierze(int sila, int inicjatywa, int pozX, int pozY, Swiat& swiat, char reprezentacja, char kolor)
	:Organizm(sila, inicjatywa, pozX, pozY, swiat, reprezentacja, kolor)
{}

void Zwierze::akcja()
{
	bool czyIstnieje = true;
	if (wiek)
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
		if ( (other && kolizja(other, czyIstnieje)) || !other )
		{
			pozX = newX;
			pozY = newY;
		}
	}

	if(czyIstnieje)
		starzejSie();
}

int Zwierze::kolizja(Organizm* other, bool& istnieje)
{
	if (other->getReprezentacja() == reprezentacja)
	{
		rozmnazanie(other);
		return 0;
	}

	int specjalna = specjalnaWalka(other);

	if (!specjalna && walkaWygrana(other))
		return 1;

	if (specjalna != 3 && specjalna!=0)
		return specjalna - 1;

	istnieje = false;
	return 0;
}

int Zwierze::specjalnaWalka(Organizm* atakowany)
{
	int specjal = atakowany->specjalnaUmiejetnosc(this);
	if (!specjal)
		return 0;

	return specjal;
}

bool Zwierze::walkaWygrana(Organizm* atakowany)
{
	if (atakowany->getSila() > sila)
	{
		swiat.komentator.oglosZabicie(atakowany, this);
		delete this;
		return false;
	}

	swiat.komentator.oglosZabicie(this, atakowany);
	delete atakowany;
	return true;
}

Zwierze::~Zwierze()
{}