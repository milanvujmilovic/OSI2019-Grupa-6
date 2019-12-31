#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<ctime>

class Dogadjaj
{

	friend std::ostream operator<<(std::ostream& stream, const Dogadjaj& other)
	{
		stream << "Naziv: " << other.naziv << std::endl;
		stream << "Kategorija: " << other.vrsta << std::endl;
		stream << "Lokacija: " << other.lokacija << std::endl;
		stream << "Opis: " << other.opis << std::endl;
		stream << "Datum: " << other.datum.tm_mday << "." << other.datum.tm_mon << "." << other.datum.tm_year << "." << " " << other.datum.tm_hour << ":" << other.datum.tm_min << std::endl;
		stream << "Komentari: " << std::endl;
		for(auto x:other.komentari)
		{
			stream<<x<<std::endl;
		}
	}

	std::string naziv;
	std::vector<std::string> komentari;
	std::string opis;
	std::tm datum = { 0,0,0,0,0,0,0,0,0 };
	std::string vrsta;  //kategorija
	std::string lokacija;


public:
	Dogadjaj() = default;
	~Dogadjaj() = default;
	Dogadjaj(std::string naziv,std::string vrsta,std::string opis, std::string lokacija,std::tm datum) : naziv(naziv), vrsta(vrsta), datum(datum),opis(opis), lokacija(lokacija) 
	{}
	
	Dogadjaj(const Dogadjaj& dogadjaj)
	{
		this->naziv =dogadjaj.naziv;
		this->vrsta = dogadjaj.vrsta;
		this->lokacija = dogadjaj.lokacija;
		this->datum = dogadjaj.datum;
		this->opis = dogadjaj.opis;
		for (auto x : dogadjaj.komentari)
		{
			this->komentari.push_back(x);
		}

	}


	Dogadjaj(Dogadjaj&& dogadjaj)	noexcept
	{
		this->naziv = dogadjaj.naziv;
		this->vrsta = dogadjaj.vrsta;
		this->lokacija = dogadjaj.lokacija;
		this->datum = dogadjaj.datum;
		this->opis = dogadjaj.opis;
		this->komentari = dogadjaj.komentari;
		for (auto x : dogadjaj.komentari)
		{
			this->komentari.push_back(x);
		}
	}


	void setNaziv(std::string naziv) {this->naziv = naziv; }
	std::string getNaziv() { return this->naziv; }

	void setVrsta(std::string vrsta) { this->vrsta = vrsta; }
	std::string getVrsta() { return this->vrsta; }

	void setDatum(std::tm datum) { this->datum = datum; }
	std::tm getDatum() { return this->datum; }

	void setLokacija(std::string lokacija) { this->lokacija = lokacija; }
	std::string getLokacija() { return this->lokacija; }

	void setOpis(std::string opis) { this->opis = opis; }
	std::string getOpis() { return this->opis; }

	void setKomentar(std::string komentar) { komentari.push_back(komentar); }
	void izlistajKomentare() { for (auto x : komentari) { std::cout << x << std::endl; } }


	void upisDogadjaja()
	{
		std::ofstream file;
		file.open("Dogadjaji.txt", std::ios::app);
		if (file.is_open())
		{
			file << this->naziv << std::endl;
			file << this->vrsta << std::endl;
			file << this->opis << std::endl;
			file << this->lokacija << std::endl;
			file << this->datum.tm_mday << "." << datum.tm_mon << "." << this->datum.tm_year <<this->datum.tm_hour <<std::endl;
			file << this->komentari.size() << std::endl;
			for (auto x : this->komentari)
				file << x << std::endl;
			file.close();
		}
	}

	void izbrisiDogadjaj()
	{
		std::string temp;
		int broj;
		std::ifstream ispis;
		ispis.open("Dogadjaji.txt", std::ios::in);
		std::fstream upis;
		upis.open("Temp.txt", std::ios::in | std::ios::out | std::ios::app);
		while (!ispis.eof()) 
		{
			getline(ispis, temp);
			if (this->naziv == temp)
			{
				getline(ispis, temp);
				getline(ispis, temp);
				getline(ispis, temp);
				getline(ispis, temp);
				getline(ispis, temp);
				broj=std::stoi(temp);
				for (int i = 0; i < broj; i++)
				{
					getline(ispis, temp);

				}
			}
			else
			{
				upis << temp << std::endl;
			}
		}
		ispis.close();
		upis.close();
		remove("Dogadjaji.txt");

		rename("Temp.txt", "Dogadjaji.txt");

	}

	void print()
	{
		std::cout << this;

	}

	
	


};