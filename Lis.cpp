#include "Lis.h"
#include "constants.h"

Lis::Lis(int pozX, int pozY, Swiat& swiat)
	:Zwierze(3, 7, pozX, pozY, swiat, REPREZENTACJA_LISA)
{}

Organizm* Lis::stworzOrganizm(int pozX, int pozY)
{
	return new Lis(pozX, pozY, swiat);
}

void Lis::akcja()
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
		if ( (other && other->getSila()<sila && kolizja(other, czyIstnieje)) || !other)
		{
			pozX = newX;
			pozY = newY;
		}
	}

	if(czyIstnieje)
		starzejSie();
}

Lis::~Lis()
{}