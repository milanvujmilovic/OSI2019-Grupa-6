#include "Anonimus.h"

Anonimus::Anonimus()
{
	ime = "";
}

void Anonimus::igrajKviz(std::fstream& pitanja, std::fstream& odgovori)
{
	int br = 0, n = 10;
	std::string pomocna, x, c, a ,b ,ce;
	a = 'a';
	b = 'b';
	ce = 'c';
	do {
		std::getline(pitanja, pomocna);
		std::cout << pomocna << std::endl;
		std::getline(pitanja, pomocna);
		std::cout << pomocna << std::endl;
		std::getline(pitanja, pomocna);
		std::cout << pomocna << std::endl;
		std::getline(pitanja, pomocna);
		std::cout << pomocna << std::endl;
		std::getline(odgovori, x);
		do {
			std::cout << "Unesite odgvoro (a,b ili c) :" << std::endl;
			std::cin >> c;
		} while ((c.compare(a) != 0) && (c.compare(b) != 0) && (c.compare(ce) != 0));
			if ((c.compare(a) == 0) || (c.compare(b) == 0) || (c.compare(ce) == 0))
			{
				if (c.compare(x) == 0)
				{
					std::cout << "Tacan odgovor!" << std::endl;
					br++;
				}
				else
					std::cout << "Pogresan odgovor!" << std::endl;
			}
		n--;
	} while (n);
	std::cout << "Vas konacan rezultat je: " << br << " tacnih odgovora od 10 mogucih."<<std::endl<<"         Hvala na ucestvovanju!"<<std::endl;
}

Anonimus::~Anonimus()
{
}
