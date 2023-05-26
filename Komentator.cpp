#include "Komentator.h"
#include "Organizm.h"
#include "Czlowiek.h"

Komentator::Komentator()
{
	for (int i = 0; i < LIMIT_KOMENTARZY; i++)
		komentarze[i] = "";
}

string Komentator::getKomentarz(int ktory)
{
	if (ktory < LIMIT_KOMENTARZY)
		return komentarze[ktory];

	return "";
}

void Komentator::addKomentarz(string komentarz)
{
	for (int i = 0; i < LIMIT_KOMENTARZY; i++)
	{
		if (komentarze[i] == "")
		{
			komentarze[i] = komentarz;
			break;
		}
	}
}

void Komentator::setOUmiejetnosci(string komentarz)
{
	oUmiejetnosci = komentarz;
}

void Komentator::oglosZabicie(Organizm* kto, Organizm* kogo)
{
	string text;
	if (kogo->getInicjatywa())
	{
		text = kto->organizmToString();
		text += " zabil " + kogo->organizmToString();
		addKomentarz(text);
		return;
	}

	text = kto->organizmToString();
	text += " zjadl " + kogo->organizmToString();
	addKomentarz(text);
}

void Komentator::oglosZwiekszenieSily(Organizm* kto, int oIle)
{
	string text = "Zwiekszono sile " + kto->organizmToString();
	text += " z " + to_string(kto->getSila() - oIle);
	text += " na " + to_string(kto->getSila());
	addKomentarz(text);
}

void Komentator::oglosZatrucie(Organizm* kto, Organizm* kim)
{
	string text = kto->organizmToString() + " zatrul sie ";
	text += kim->organizmToString() + " i umarl";
	addKomentarz(text);
}

void Komentator::oglosRozmnozenie(Organizm* a, Organizm* b)
{
	string text;
	if (a != b)
	{
		text = a->organizmToString() + " i ";
		text += b->organizmToString() + " sie rozmnozyly ";
		addKomentarz(text);
		return;
	}

	text = a->organizmToString() + " rozsial sie ";
	addKomentarz(text);
}

void Komentator::oglosOdbicieAtaku(Organizm* kto, Organizm* czyj)
{
	string text = kto->organizmToString() + " odbil atak ";
	text += czyj->organizmToString();
	addKomentarz(text);
}

void Komentator::oglosUcieczke(Organizm* kto, Organizm* przedKim)
{
	string text = kto->organizmToString() + " uciekl przed walka z ";
	text += przedKim->organizmToString();
	addKomentarz(text);
}

void Komentator::oglosUmiejetnoscCzlowieka(Czlowiek* uzytkownik)
{
	string text="Umiejetnosc specjalna " + uzytkownik->organizmToString();
	if (uzytkownik->getUmiejWlacz())
		text += " aktywna, poziom naladowania wynosi: ";
	else
		text += " nieaktywna, poziom naladowania wynosi: ";

	text += to_string(uzytkownik->getUmiejLicz()) + "/5";

	oUmiejetnosci = text;
}

void Komentator::oglosSpalenie(Organizm* kto, Organizm* kogo)
{
	string text = kto->organizmToString() + " spalil ";
	text += kogo->organizmToString() + " uzywajac specjalnej umiejetnosci";
	addKomentarz(text);
}

void Komentator::skomentujChecZapisu()
{
	cout << "Wykonaj ruch, aby dokonczyc ture i wtedy gra zostanie zapisana" << endl;
}

void Komentator::skomentujStanUmiejetnosci()
{
	cout << oUmiejetnosci << endl;
}

void Komentator::skomentujTure()
{
	int i = 0;
	while (i < LIMIT_KOMENTARZY && komentarze[i] != "")
	{
		cout << komentarze[i] << endl;
		komentarze[i] = "";
		i++;
	}
}

Komentator::~Komentator()
{}