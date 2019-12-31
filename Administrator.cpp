#include "Administrator.h"
#include <time.h>
int Administrator::provjeraPrijave()
{
	if (ime == "" && sifra == "")
	{
		return 1;
	}
	else
	{
		return 0;
	}
	return 0;
}
int Administrator::prijava()
{
	std::string novoIme = "";
	std::string novaSifra = "";

	std::string pomIme = "";
	std::string pomSifra = "";

	bool pronadjenNalog = false;

	std::cout << "Molimo vas unesite korisnicko ime i lozinku:\n";
	std::cout << "Korisnicko ime: ";
	std::cin >> novoIme;
	std::cout << "Lozinka: ";
	std::cin >> novaSifra;
	std::cout << std::endl;

	std::ifstream fajlNalozi;
	fajlNalozi.open("Nalozi.txt",std::ios::in);
	while (!fajlNalozi.eof())
	{
		getline(fajlNalozi, pomIme);
		getline(fajlNalozi, pomSifra);
		if (pomIme == novoIme && pomSifra == novaSifra)
		{
			pronadjenNalog = true;
			break;
		}
	}
	fajlNalozi.close();
	if (pronadjenNalog == false)
	{
		std::cout << "Pogresan ili nepostojeci nalog!" << std::endl;
		return 1;
	}
	else
	{
		ime = novoIme;
		sifra = novaSifra;
		std::cout << "Usjpjesno ste se prijavili na sistem!" << std::endl;
		return 0;
	}
}

std::vector<Dogadjaj> Administrator::citajDogadjaje()
{
	std::vector<Dogadjaj> nizDogadjaja;
	std::ifstream fajlDogadjaji;
	fajlDogadjaji.open("Dogadjaji.txt");
	while (!fajlDogadjaji.eof())
	{
		Dogadjaj pomDogadjaj("", "", "", "", { 0,0,0,0,0,0,0,0,0});
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
		std::vector<std::string> pomVektor = split(pomString, '-');//vidicemo ove li biti problema kad kalaba popravi format
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
	return nizDogadjaja;
}

void Administrator::sortirajDogadjaje(std::vector<Dogadjaj> nizDogadjaja)
{
	std::string parametar;//ime,datum,kategorija,lokacija
	while (parametar != "ime" || parametar != "lokacija" || parametar != "datum" || parametar != "kategorija")
	{
		std::cout << "Unesite validan parametar za sortiranje:";
		std::cin >> parametar;
	}
	if (parametar == "ime")
	{
		//std::sort(nizDogadjaja.begin(), nizDogadjaja.end(), [](Dogadjaj a, Dogadjaj b) {return a.getNaziv() < b.getNaziv(); });
	}
	else if (parametar == "kategorija")
	{
		//std::sort(nizDogadjaja.begin(), nizDogadjaja.end(), [](Dogadjaj a, Dogadjaj b) {return a.getVrsta() < b.getVrsta(); });
	}
	else if (parametar == "datum")
	{
		/*std::sort(nizDogadjaja.begin(), nizDogadjaja.end(), [](Dogadjaj a, Dogadjaj b)
			{
				std::tm datum1 = a.getDatum();
				std::tm datum2 = b.getDatum();
				if (datum1.tm_year < datum2.tm_year)
				{
					return true;
				}
				else if (datum1.tm_year == datum2.tm_year && datum1.tm_mon < datum2.tm_mon)
				{
					return true;
				}
				else if (datum1.tm_year == datum2.tm_year && datum1.tm_mon == datum2.tm_mon && datum1.tm_mday < datum2.tm_mday)
				{
					return true;
				}
				else
				{
					return false;
				}
			});*/
	}
	else
	{
		//std::sort(nizDogadjaja.begin(), nizDogadjaja.end(), [](Dogadjaj a, Dogadjaj b) {return a.getLokacija() < b.getLokacija(); });
	}
}

bool Administrator::provjeraKategorije(std::string nazivKategorije)
{
	std::ifstream fajlKategorije;
	fajlKategorije.open("Kategorije.txt");
	bool pronadjena = false;
	while (!fajlKategorije.eof())
	{
		std::string pomKat = "";
		getline(fajlKategorije, pomKat);
		if (pomKat == nazivKategorije)
		{
			pronadjena = true;
			fajlKategorije.close();
			return pronadjena;
		}
	}
	fajlKategorije.close();
	return pronadjena;
}

void Administrator::initDogadjaja()
{
	std::string ime;
	std::string lokacija;
	std::string opis;
	std::string kategorija;
	std::tm datum;
	int dan;
	int mjesec;
	int godina;
	int sat;
	int min;
	std::cout << "Kreiranje dogadjaja" << std::endl;
	getchar();
	std::cout << "Ime dogadjaja:";
	std::getline(std::cin, ime);
	std::cout << "Kategorija:";
	std::cin >> kategorija;
	while (provjeraKategorije(kategorija) != true)
	{
		std::cout << "Unesite postojecu kategoriju:";
		std::cin >> kategorija;
	}
	getchar();
	std::cout << "Lokacija odrzavanja:";
	std::getline(std::cin, lokacija);
	std::cout << "Opis dogadjaja:";
	std::getline(std::cin, opis);
	std::cout << "Datum odrzavanja:\n";
	std::cout << "Dan:";
	std::cin >> dan;
	std::cout << "Mjesec:";
	std::cin >> mjesec;
	std::cout << "Godina:";
	std::cin >> godina;
	std::cout << "Vreijeme odrzavanja:\n";
	std::cout << "Sati:";
	std::cin >> sat;
	std::cout << "Minuti:";
	std::cin >> min;
	datum.tm_mday = dan;
	datum.tm_mon = mjesec;
	datum.tm_year = godina;
	datum.tm_hour = sat;
	datum.tm_min = min;
	Dogadjaj noviDogadjaj{ ime,kategorija,opis,lokacija,datum };
	noviDogadjaj.upisDogadjaja();
}

std::vector<std::string> Administrator::split(const std::string& s, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream token_stream(s);
	while (std::getline(token_stream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

Administrator::~Administrator()
{

}

void Administrator::kreirajDogadjaj()
{
	if (provjeraPrijave())
	{
		std::string odgovor;
		std::cout << "Niste prijavljeni u sistem.\nDa li zelite da se prijavite?(Da ili Ne)";// << std::endl;
		std::cin >> odgovor;
		while (odgovor != "Da" || odgovor != "da" || odgovor != "DA" || odgovor != "Ne" || odgovor != "ne" || odgovor != "NE") 
		{
			if (odgovor == "Da" || odgovor == "da" || odgovor == "DA")
			{
				if (prijava())
				{
					std::cout << "Nemoguce kreiranje dogadjaja.Nemate administratorski nalog.";//<< std::endl;
					break;
				}
				else
				{
					initDogadjaja();
					break;
				}
			}
			else
			{
				return;
			}
		}
	}
	else
	{
		initDogadjaja();
	}
	return;
}

int Administrator::urediDogadjaj(std::string naziv)
{
	/*procitaj dogadjaj iz memorije na osnovu imena ili imena i datuma*/
	/*odabir parametara koji se mjenjaju u jednu while(true) petlju staviti da moze da mijenja koliko oce i lupiti q za izlaz*/
	/*update dogadjaja u memoriji*/
	return 0;
}

int Administrator::pregledDogadjaja()
{
	std::vector<Dogadjaj> nizDogadjaja = citajDogadjaje();
	std::cout << "Zelite li da sortiran pregled dogadjaja?(Da ili Ne)";
	std::string odgovor;
	std::cin >> odgovor;
	if (odgovor == "Ne" || odgovor == "ne" || odgovor == "NE")
	{
		for (auto x : nizDogadjaja)
		{
			x.print();
		}
	}
	else
	{
		sortirajDogadjaje(nizDogadjaja);
		for (auto x : nizDogadjaja)
		{
			x.print();
		}
	}
	return 0;
}

int Administrator::pregledKategorija()
{
	std::cout << "Kategorije dogadjaja u gradu:\n";
	std::ifstream fajlKategorije;
	fajlKategorije.open("Kategorije.txt");
	std::string pomString;
	if (fajlKategorije.is_open())
	{
		while (!fajlKategorije.eof())
		{
			getline(fajlKategorije, pomString);
			std::cout << pomString << std::endl;
		}
		fajlKategorije.close();
	}
	return 0;
}

int Administrator::dodajKategoriju()
{
	/*ucitavanje kategorija u memoriju
	provjera da li kategorija vec postoji
	provjera je li osnovna kategorija
	dodavanje kategorije*/
	return 0;
}

int Administrator::obrisiKategoriju()
{
	/*ucitavanje kategorija u memoriju
	provjera da li kategorija vec postoji
	provjera je li osnovna kategorija
	brisanje kategorije
	update svih dogadjaja koji posjeduju tu kategoriju*/
	return 0;
}

