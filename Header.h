#pragma once
#include <iostream>
#include <string>
#include <vector>
#include<ctime>

class Dogadjaj
{
	std::string naziv;
	std::vector<std::string> komentari;
	std::string opis;
	std::tm datum = { 0,0,0,0,0,0,0,0,0 };
	std::string vrsta;  //kategorija
	std::string lokacija;


public:
	Dogadjaj() = default;

	Dogadjaj(std::string naziv,std::string vrsta, std::string lokacija,std::tm datum) : naziv(naziv), vrsta(vrsta), datum(datum), lokacija(lokacija) 
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

	void setOpis() { this->opis = opis; }
	std::string getOpis() { return this->opis; }

	void setKomentar(std::string komentar) { komentari.push_back(komentar); }
	void izlistajKomentare() { for (auto x : komentari) { std::cout << x << std::endl; } }




};