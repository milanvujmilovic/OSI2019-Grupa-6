#include "Anonimus.h"

Anonimus::Anonimus()
{
	std::string tmp = "Guest";
	int broj;
	broj = rand();
	broj = broj % 1000;
	char* tmp2 = new char[5];
	_itoa(broj, tmp2, 10);
	ime = tmp + tmp2;
	delete[5] tmp2;
}

void Anonimus::pisiDogadjaj(std::vector<std::string>& dogadjaj)
{
	std::cout << "Dogadjaj:\n";
	for (std::string s : dogadjaj)
		std::cout << s << std::endl;
	std::cout << std::endl;
}

int Anonimus::brojDogadjaja(std::ifstream& dat)
{
	std::string pomocna;
	for (int i = 0; i < 12; i++)
		std::getline(dat, pomocna);
	return std::stoi(pomocna);
}

tm& Anonimus::konverzijaDatuma()
{
	std::time_t nova = time(0);
	tm* p = localtime(&nova);
	return *p;
}

void Anonimus::pregledDanasnjihDogadjaja(std::ifstream& dat1, std::ifstream& dat2)
{
	std::string pomocna, pom;
	std::vector<std::string> dogadjaj;
	int k = 0, br = brojDogadjaja(dat1);
	for (int i = 0; i < br; i++)
	{
		for (int i = 0; i < 5; i++)
		{
			std::getline(dat2, pomocna);
			dogadjaj.push_back(pomocna);
		}
		std::stringstream ss(pomocna); //stringstream se koristi za citanje stringa(konkretno datuma) i razdvaja dan mjesec i godinu drugim argumentom('.')
		std::vector<std::string> datum; //vector sluzi za smijestanje dana, mjeseca i godine kao niza stringova
		while (std::getline(ss, pom, '.')) //getline se koristi za razdvajanje stringa na dan, mjesec i godinu pomocu tacke
			datum.push_back(pom); //u vector se smijestaju dan, mjesec i godina
		int d = std::stoi(datum[0]), m = std::stoi(datum[1]), g = std::stoi(datum[2]); //datum[0], datum[1] i datum[2] su stringovi koji predstavljaju dan, mjesec i godinu
		tm p = konverzijaDatuma();
		std::getline(dat2, pomocna);
		int br_kom = stoi(pomocna);
		for (int i = 0; i < br_kom; i++)
		{
			std::getline(dat2, pomocna);
			dogadjaj.push_back(pomocna);
		}
		if (d == p.tm_mday && m == p.tm_mon + 1 && g == p.tm_year + 1900) {
			pisiDogadjaj(dogadjaj); k++;
		}
		dogadjaj.clear(); //resetovanje vektora (niza)
	}
	if (k == 0) std::cout << "Danas nema dogadjaja u gradu." << std::endl;
	dat1.seekg(0); dat2.seekg(0);
}

void Anonimus::pregledBuducihDogadjaja(std::ifstream& dat1, std::ifstream& dat2)
{
	std::string pomocna, pom;
	std::vector<std::string> dogadjaj;
	int k = 0, br = brojDogadjaja(dat1);
	for (int i = 0; i < br; i++)
	{
		for (int i = 0; i < 5; i++)
		{
			std::getline(dat2, pomocna);
			dogadjaj.push_back(pomocna);
		}
		std::stringstream ss(pomocna);
		std::vector<std::string> datum;
		while (std::getline(ss, pom, '.'))
			datum.push_back(pom);
		int d = std::stoi(datum[0]), m = std::stoi(datum[1]), g = std::stoi(datum[2]);
		tm p = konverzijaDatuma();
		std::getline(dat2, pomocna);
		int br_kom = stoi(pomocna);
		for (int i = 0; i < br_kom; i++)
		{
			std::getline(dat2, pomocna);
			dogadjaj.push_back(pomocna);
		}
		if (g > p.tm_year + 1900 || (g == p.tm_year + 1900 && m > p.tm_mon + 1) || (g == p.tm_year + 1900 && m == p.tm_mon + 1 && d > p.tm_mday)) {
			pisiDogadjaj(dogadjaj); k++;
		}
		dogadjaj.clear();
	}
	if (k == 0) std::cout << "Nema buducih dogadjaja u gradu." << std::endl;
	dat1.seekg(0); dat2.seekg(0);
}

void Anonimus::pregledProslihDogadjaja(std::ifstream& dat1, std::ifstream& dat2)
{
	std::string pomocna, pom;
	std::vector<std::string> dogadjaj;
	int k = 0, br = brojDogadjaja(dat1);
	for (int i = 0; i < br; i++)
	{
		for (int i = 0; i < 5; i++)
		{
			std::getline(dat2, pomocna);
			dogadjaj.push_back(pomocna);
		}
		std::stringstream ss(pomocna);
		std::vector<std::string> datum;
		while (std::getline(ss, pom, '.'))
			datum.push_back(pom);
		int d = std::stoi(datum[0]), m = std::stoi(datum[1]), g = std::stoi(datum[2]);
		tm p = konverzijaDatuma();
		std::getline(dat2, pomocna);
		int br_kom = stoi(pomocna);
		for (int i = 0; i < br_kom; i++)
		{
			std::getline(dat2, pomocna);
			dogadjaj.push_back(pomocna);
		}
		if (g < p.tm_year + 1900 || (g == p.tm_year + 1900 && m < p.tm_mon + 1) || (g == p.tm_year + 1900 && m == p.tm_mon + 1 && d < p.tm_mday)) {
			pisiDogadjaj(dogadjaj); k++;
		}
		dogadjaj.clear();
	}
	if (k == 0) std::cout << "Nema buducih dogadjaja u gradu." << std::endl;
	dat1.seekg(0); dat2.seekg(0);
}

void Anonimus::igrajKviz(std::ifstream& pitanja, std::ifstream& odgovori)
{
	int br = 0, n = 10;
	std::string pomocna, x, c, a, b, ce;
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
			std::cout << "Unesite odgovor (a,b ili c) :" << std::endl;
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
	std::cout << "Vas konacan rezultat je: " << br << " tacnih odgovora od 10 mogucih." << std::endl << "         Hvala na ucestvovanju!" << std::endl;
	pitanja.seekg(0);
	odgovori.seekg(0);
}

void Anonimus::pregledPoKategoriji(std::ifstream& dogadjaj, std::ifstream& konfiguracija, std::ifstream& kategorije)
{
	std::string pomocna1, pomocna2, kategorija, ponuda;
	std::vector<std::string> dog;
	int brojD, brojK, kontrola;
	brojD = brojDogadjaja(konfiguracija);
	do {
		std::cout << "Izaberite zeljenu kategoriju:" << std::endl;
		while (!kategorije.eof())
		{
			std::getline(kategorije, ponuda);
			std::cout << "-" << ponuda << std::endl;
		}
		std::cin >> kategorija;
		std::cout << std::endl;
		std::transform(kategorija.begin(), kategorija.end(), kategorija.begin(), ::tolower);
		for (int i = 0; i < brojD; i++)
		{
			int pom = 0;
			std::getline(dogadjaj, pomocna1);
			dog.push_back(pomocna1);
			std::getline(dogadjaj, pomocna1);
			dog.push_back(pomocna1);
			std::transform(pomocna1.begin(), pomocna1.end(), pomocna1.begin(), ::tolower);
			if (kategorija.compare(pomocna1) == 0)
				pom = 1;
			std::getline(dogadjaj, pomocna1);
			dog.push_back(pomocna1);
			std::getline(dogadjaj, pomocna1);
			dog.push_back(pomocna1);
			std::getline(dogadjaj, pomocna1);
			dog.push_back(pomocna1);
			std::getline(dogadjaj, pomocna1);
			brojK = std::stoi(pomocna1);
			dog.push_back(pomocna1);
			for (int j = 0; j < brojK; j++)
			{
				std::getline(dogadjaj, pomocna1);
				dog.push_back(pomocna1);
			}
			if (pom == 1)
				pisiDogadjaj(dog);
			dog.clear();

		}
		dogadjaj.seekg(0);
		konfiguracija.seekg(0);
		kategorije.seekg(0);
		std::cout << std::endl;
		std::cout << "Ako zelite nastaviti pretragu po kategoriji unesite '1' , ako zelite napustiti pretragu unesite '0'." << std::endl;
		std::cin >> kontrola;
	} while (kontrola);
}

Anonimus::~Anonimus()
{

}