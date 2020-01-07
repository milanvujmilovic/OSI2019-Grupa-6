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
    std::cin.ignore();
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

void Administrator::citajDogadjaje(std::vector<Dogadjaj>& nizDogadjaja)
{
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

void Administrator::sortirajDogadjaje(std::vector<Dogadjaj>& nizDogadjaja,std::string parametar)
{
	if (parametar == "ime" || parametar == "lokacija" || parametar == "datum" || parametar == "kategorija")
	{
		if (parametar == "ime")
		{
			std::sort(nizDogadjaja.begin(), nizDogadjaja.end(), [](Dogadjaj a, Dogadjaj b) {return a.getNaziv() < b.getNaziv(); });
		}
		else if (parametar == "kategorija")
		{
			std::sort(nizDogadjaja.begin(), nizDogadjaja.end(), [](Dogadjaj a, Dogadjaj b) {return a.getVrsta() < b.getVrsta(); });
		}
		else if (parametar == "datum")
		{
			std::sort(nizDogadjaja.begin(), nizDogadjaja.end(), [](Dogadjaj a, Dogadjaj b)
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
				});
		}
		else
		{
			std::sort(nizDogadjaja.begin(), nizDogadjaja.end(), [](Dogadjaj a, Dogadjaj b) {return a.getLokacija() < b.getLokacija(); });
		}
	}
	else
	{
		std::cout << "Unijeli ste nevazeci parametar pregleda!"<< std::endl;
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
	std::cout << "Vrijeme odrzavanja:\n";
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
	kofiguracija();
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

int Administrator::urediDogadjaj()
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
					uredi();
					break;
				}
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		uredi();
	}
	return 0;
}

int Administrator::pregledDogadjaja()
{
	std::vector<Dogadjaj> nizDogadjaja;
	citajDogadjaje(nizDogadjaja);
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
		std::string parametar;
		std::cout << "Unesite parametar za sortiranje:";
		std::cin >> parametar;
		sortirajDogadjaje(nizDogadjaja,parametar);
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
					dodaj();
					break;
				}
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		dodaj();
	}
	return 0;
}

int Administrator::obrisiKategoriju()
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
					brisi();
					break;
				}
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		brisi();
	}
	return 0;
}
int Administrator:: dodaj()
{
    std::string pomString,novaKategorija;
    std::ifstream fajlKategorije;
    std::ofstream fajl;
    fajlKategorije.open("Kategorije.txt");
    std::cout<<"Unesite novu kategoriju:\n";
    getline(std::cin,novaKategorija);
    if (fajlKategorije.is_open())
    {
        while (!fajlKategorije.eof())
        {
            getline(fajlKategorije, pomString);
            if(pomString.compare(novaKategorija)==0)
            {
                std::cout<<"Kategorija vec postoji\n";
                fajlKategorije.close();
                return 0;
            }
        }
        fajlKategorije.close();
    }
    fajl.open("Kategorije.txt", std::ios_base::app);
    if (fajl.is_open())
    {
		/*Obezbjediti korektan unos ako nema ni jedne kategorije*/
		fajl << std::endl;//radi kad se dodaje na kraj
		fajl << novaKategorija;//radi kad se dodaje na kraj
        fajl.close();
    }
    return 0;
}
int Administrator:: brisi()
{
    std::string temp;
    std::string kategorija;
    std::cout<<"Unesite kategoriju koju zelite obrisati:\n";
    getline(std::cin,kategorija);
    std::ifstream ispis;
    ispis.open("Kategorije.txt");
    std::ofstream upis("Temp.txt");
    if(ispis.is_open() && upis.is_open())
    {
        ispis.seekg(0,ispis.end);
        int duzina=ispis.tellg();
        ispis.seekg(0,ispis.beg);
        while (ispis.tellg()<duzina)
        {
            getline(ispis, temp);
            if (kategorija.compare(temp)!=0)
            {
                upis << temp << std::endl;
            }
        }
        ispis.close();
        upis.close();
        remove("Kategorije.txt");
        rename("Temp.txt", "Kategorije.txt");
    }
    return 0;
}
void Administrator:: uredi()
{
    std::string naziv("");
    std::string novi("");
    std::cout<<"Unesite ime dogadjaja koji zelite promijeniti:\n";
    getline(std::cin,naziv);
    std::vector <Dogadjaj> dogadjaji;
    Dogadjaj pomDogadjaj;
    citajDogadjaje(dogadjaji);
    int pom=0,i=0,pos;
    for(Dogadjaj &temp: dogadjaji)
    {
        if(((naziv.compare(temp.getNaziv()))==0))
        {
            pom=1;
            pos=i;
        }
        i++;
    }
    if(pom==1)
    {
        int uslov=1;
        char brojParametra;
        std::cout<<"Izaberite broj ispred parametra koji zelite urediti:\n1-naziv\n2-kategorija\n3-opis\n4-Lokacija\n5-Datum\nq-prekinite uredjivanje\n";
        while(uslov)
        {
            std::cin>>brojParametra;
            std::cin.ignore();
            if(brojParametra=='1')
            {
                std::cout<<"Unesite novi naziv: ";
                getline(std::cin,novi);
                dogadjaji[pos].setNaziv(novi);
				uslov = 0;
            }
            else if(brojParametra=='2')
            {
                std::cout<<"Unesite kategoriju: ";
                getline(std::cin,novi);
				if (provjeraKategorije(novi))
				{
					dogadjaji[pos].setVrsta(novi);
					uslov = 0;
				}
				else
				{
					std::cout << "Kategorija nije pronadjena!\n";
					uslov = 0;
				}
            }
            else if(brojParametra=='3')
            {
                std::cout<<"Unesite novi opis: ";
                getline(std::cin,novi);
                dogadjaji[pos].setOpis(novi);
				uslov = 0;
            }
            else if(brojParametra=='4')
            {
                std::cout<<"Unesite novi lokaciju: ";
                getline(std::cin,novi);
                dogadjaji[pos].setLokacija(novi);
				uslov = 0;
            }
            else if(brojParametra=='5')
            {
                std::tm datum;
                int dan,mjesec,godina,sat,min;
                std::cout << "Unesite novi datum odrzavanja:\n";
                std::cout << "Dan:";
                std::cin >> dan;
                std::cout << "Mjesec:";
                std::cin >> mjesec;
                std::cout << "Godina:";
                std::cin >> godina;
                std::cout << "Vrijeme odrzavanja:\n";
                std::cout << "Sati:";
                std::cin >> sat;
                std::cout << "Minuti:";
                std::cin >> min;
                datum.tm_mday = dan;
                datum.tm_mon = mjesec;
                datum.tm_year = godina;
                datum.tm_hour = sat;
                datum.tm_min = min;
                dogadjaji[pos].setDatum(datum);
				uslov = 0;
                }
                else if(brojParametra=='q')
                    uslov=0;
            }
            remove("Dogadjaji.txt");
            for(Dogadjaj &temp: dogadjaji)
            {
                temp.upisDogadjaja();
            }
        }
        else
    printf("Uneseni dogadjaj ne postoji\n");
}
void Administrator::kofiguracija()
{
	std::fstream fajl;
	std::vector<std::string> pomVek;
	fajl.open("Konfiguraciona_datoteka.txt", std::ios::in | std::ios::out);
	std::string pomString;
	int pom=0;
	if (fajl.is_open())
	{
		std::cout << "uspjeh";
		for (int i = 0; i < 12; ++i)
		{
			getline(fajl, pomString);
			pomVek.push_back(pomString);
		}
		pom = stoi(pomString);
		pom++;
		fajl.close();
		std::fstream upis;
		upis.open("Temp.txt", std::ios::in | std::ios::out | std::ios::app);
		for (int i = 0; i < 12; ++i)
		{
			if (i < 11)
			{
				upis << pomVek[i] << std::endl;
			}
			else
				upis << pom;
		}
		upis.close();
		remove("Konfiguraciona_datoteka.txt");
		rename("Temp.txt", "Konfiguraciona_datoteka.txt");
	}

}
void Administrator::odjava()
{
    this->ime="";
    this->sifra="";
    std::cout<<"Uspjesno ste se odjavili\n";
}
