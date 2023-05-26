#include "Organizm.h"
#include <cstdlib>
#include "constants.h"

Organizm::Organizm(int sila, int inicjatywa, int pozX, int pozY, Swiat& swiat, char reprezentacja, char kolor)
	:sila(sila), inicjatywa(inicjatywa), pozX(pozX), pozY(pozY), wiek(0), swiat(swiat), reprezentacja(reprezentacja), kolor(kolor)
{
	swiat.addOrganizm(this);
}

void Organizm::setSila(int nowaSila)
{
	sila = nowaSila;
}

void Organizm::setWiek(int nowyWiek)
{
	wiek = nowyWiek;
}

bool Organizm::czyOtoczony()
{
	int width = swiat.getSizeX();
	int height = swiat.getSizeY();

	if (pozX - 1 >= 0 && !swiat.ktoNaPolu(pozX - 1, pozY))
		return false;

	if (pozX + 1 < width && !swiat.ktoNaPolu(pozX + 1, pozY))
		return false;

	if (pozY - 1 >= 0 && !swiat.ktoNaPolu(pozX, pozY - 1))
		return false;

	if (pozY + 1 < width && !swiat.ktoNaPolu(pozX, pozY + 1))
		return false;

	return true;
}

void Organizm::rozmnazanie(Organizm* other)
{
	if (!czyOtoczony())
	{
		int newX = pozX;
		int newY = pozY;
		int ruch = wylosujRuch(true);
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

		Organizm* tmp = stworzOrganizm(newX, newY);
		swiat.komentator.oglosRozmnozenie(this, other);
	}
}

int Organizm::wylosujRuch(bool musiBycWolne)
{
	int width = swiat.getSizeX();
	int height = swiat.getSizeY();
	while (true)
	{
		int random = rand() % 4;
		int newX = pozX;
		int newY = pozY;

		switch (random)
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

		if (newX >= 0 && newX < width && newY >= 0 && newY < height && (!musiBycWolne || !swiat.ktoNaPolu(newX, newY)))
		{
			return random;
		}
	}
}

string Organizm::organizmToString()
{
	string wynik = typToString();
	wynik += "[" + to_string(pozX);
	wynik += "," + to_string(pozY);
	wynik += "] s" + to_string(sila);

	return wynik;
}

string Organizm::zapisOrganizmu()
{
	string wynik = to_string(reprezentacja) + " ";
	wynik += to_string(pozX) + " ";
	wynik += to_string(pozY) + " ";
	wynik += to_string(sila) + " ";
	wynik += to_string(wiek);
	return wynik;
}

Organizm::~Organizm()
{
	swiat.removeOrganizm(this);
}