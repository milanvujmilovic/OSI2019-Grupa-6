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
	std::cout << "Dogadjaj:" << std::endl;
	std::cout << "-----------" << std::endl;
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
	std::cout << "Pregled danasnjih dogadjaja u gradu:" << std::endl;
	std::cout << "====================================" << std::endl << std::endl;
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
		if (d == p.tm_mday && m == p.tm_mon + 1 && g == p.tm_year + 1900) {
			pisiDogadjaj(dogadjaj); k++;
		}
		dogadjaj.clear(); 
	}
	if (k == 0) std::cout << "Danas nema dogadjaja u gradu." << std::endl<<std::endl;
	dat1.seekg(0); dat2.seekg(0);
}

void Anonimus::pregledBuducihDogadjaja(std::ifstream& dat1, std::ifstream& dat2)
{
	std::string pomocna, pom;
	std::vector<std::string> dogadjaj;
	int k = 0, br = brojDogadjaja(dat1);
	std::cout << "Pregled buducih dogadjaja u gradu:" << std::endl;
	std::cout << "==================================" << std::endl << std::endl;
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
	if (k == 0) std::cout << "Nema buducih dogadjaja u gradu." << std::endl<<std::endl;
	dat1.seekg(0); dat2.seekg(0);
}

void Anonimus::pregledProslihDogadjaja(std::ifstream& dat1, std::ifstream& dat2)
{
	std::string pomocna, pom;
	std::vector<std::string> dogadjaj;
	int k = 0, br = brojDogadjaja(dat1);
	std::cout << "Pregled proslih dogadjaja u gradu:" << std::endl;
	std::cout << "==================================" << std::endl<< std::endl;
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
	if (k == 0) std::cout << "Nema proslih dogadjaja u gradu." << std::endl<<std::endl;
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
			std::getline(std::cin, c);
		} while ((c.compare(a) != 0) && (c.compare(b) != 0) && (c.compare(ce) != 0));
		if ((c.compare(a) == 0) || (c.compare(b) == 0) || (c.compare(ce) == 0))
		{
			if (c.compare(x) == 0)
			{
				std::cout << "Tacan odgovor!" << std::endl<<std::endl;
				br++;
			}
			else
				std::cout << "Pogresan odgovor!" << std::endl<<std::endl;
		}
		n--;
	} while (n);
	std::cout << "Vas konacan rezultat je: " << br << " tacnih odgovora od 10 mogucih." << std::endl << "         Hvala na ucestvovanju!" << std::endl;
	pitanja.seekg(0); odgovori.seekg(0);

}

void Anonimus::pregledPoKategoriji(std::ifstream& dogadjaj, std::ifstream& konfiguracija, std::ifstream& kategorije)
{
	std::string pomocna1, pomocna2, kategorija, ponuda;
	std::vector<std::string> dog;
	int brojD, brojK,brojac;
	std::string kontrola,d,n;
	d = 'd';
	n = 'n';
	brojD = brojDogadjaja(konfiguracija);
	std::cout << "Pregled dogadjaja u gradu po kategoriji:" << std::endl;
	std::cout << "========================================" << std::endl<<std::endl;
	do {
		brojac = brojD;
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
			{
				pom = 1;
				brojac--;
			}
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
		if (brojac == brojD)
			std::cout << "Nema dogadjaja iz trazene kategorije!\n";
		dogadjaj.seekg(0);
		konfiguracija.seekg(0);
		kategorije.seekg(0);
		std::cout << std::endl;
		std::getline(std::cin, kontrola);
		do
		{
			std::cout << "Ako zelite nastaviti pretragu po kategoriji unesite 'd' , ako zelite napustiti pretragu unesite 'n'." << std::endl;
			std::getline(std::cin, kontrola);
		} while ((kontrola.compare(d)!=0) && kontrola.compare(n)!=0);
		std::cout << std::endl;
	} while (kontrola.compare(n)!=0);
}

void Anonimus::citajDogadjaje(std::vector<Dogadjaj>& nizDogadjaja)
{
	std::ifstream fajlDogadjaji;
	fajlDogadjaji.open("Dogadjaji.txt");
	while (!fajlDogadjaji.eof())
	{
		Dogadjaj pomDogadjaj("", "", "", "", { 0,0,0,0,0,0,0,0,0 });
		std::string pomString = "";
		getline(fajlDogadjaji, pomString);//cita ime
		pomDogadjaj.setNaziv(pomString);
		getline(fajlDogadjaji, pomString);//cita kategoriju
		pomDogadjaj.setVrsta(pomString);
		getline(fajlDogadjaji, pomString);//cita opis
		pomDogadjaj.setOpis(pomString);
		getline(fajlDogadjaji, pomString);//cita lokaciju
		pomDogadjaj.setLokacija(pomString);
		getline(fajlDogadjaji, pomString);//cita datum kao string
		std::tm datum;//konvertovati string u datum
		std::vector<std::string> pomVektor = split(pomString, '-');
		std::string pomDatum = pomVektor.at(0);
		std::string pomVrijeme = pomVektor.at(1);
		std::vector<std::string> pVDatum = split(pomDatum, '.');
		std::vector<std::string> pVVrijeme = split(pomVrijeme, ':');
		datum.tm_mday = stoi(pVDatum.at(0));//strpati u pomocnu funkciju
		datum.tm_mon = stoi(pVDatum.at(1));
		datum.tm_year = stoi(pVDatum.at(2));
		datum.tm_hour = stoi(pVVrijeme.at(0));
		datum.tm_min = stoi(pVVrijeme.at(1));
		pomDogadjaj.setDatum(datum);
		int brKomentara;
		getline(fajlDogadjaji, pomString);
		brKomentara = stoi(pomString);
		for (int i = 0; i < brKomentara; ++i)
		{
			getline(fajlDogadjaji, pomString);
			pomDogadjaj.setKomentar(pomString);

		}
		nizDogadjaja.push_back(pomDogadjaj);
	}
	fajlDogadjaji.close();
}

std::vector<std::string> Anonimus::split(const std::string& s, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream token_stream(s);
	while (std::getline(token_stream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

std::tm Anonimus::stringToDate(std::string)
{
	return std::tm();
}

void Anonimus::dodavanjeKomentara()
{
	std::vector<Dogadjaj> nizDogadjaja;
	citajDogadjaje(nizDogadjaja);
	std::string naziv, komentar;
	std::cout << "Za koji dogadjaj zelite da unesete komentar?" << std::endl;
	std::getline(std::cin, naziv);
	int i = 0, k = 0;
	for (Dogadjaj d : nizDogadjaja)
	{
		if (std::strcmp(naziv.c_str(), d.getNaziv().c_str()) == 0)
		{
			break;
		}
		k++;
	}
	if (k == nizDogadjaja.size())
	{
		std::cout << "Ne postoji trazeni dogadjaj." << std::endl;
	}
	else
	{
		std::ifstream fajlDogadjaji;
		fajlDogadjaji.open("Dogadjaji.txt", std::ofstream::out | std::ofstream::trunc);
		fajlDogadjaji.close();

		std::cout << "Unesite komentar:" << std::endl;
		std::getline(std::cin, komentar);
		nizDogadjaja[k].setKomentar(komentar);
		for (Dogadjaj d : nizDogadjaja)
		{
			nizDogadjaja[i].upisDogadjaja();
			i++;
		}
	}
}

Anonimus::~Anonimus()
{

}