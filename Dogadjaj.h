#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<ctime>
#include <iterator>

class Dogadjaj
{

	friend std::ostream& operator<<(std::ostream& stream, const Dogadjaj& other);

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
	
	Dogadjaj(const Dogadjaj& dogadjaj);


	Dogadjaj(Dogadjaj&& dogadjaj)noexcept;


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
	
	void operator=(const Dogadjaj& dogadjaj);

	void upisDogadjaja();

	void izbrisiDogadjaj();

	void print();
};