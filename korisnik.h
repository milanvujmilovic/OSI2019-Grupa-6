#pragma once
#include <fstream>
#include <string.h>
#include <string>
#include "Dogadjaj.h"
class Korisnik
{

	std::string name;
	const std::string FileName = "formatUpisa.txt";
	std::tm stringToDate(std::string);
public:
	void listajPoVrsti(std::string&);
	void listajPoDatumu(std::tm&);
	void ispisiDogadjaj(Dogadjaj&);
	Dogadjaj ucitajDogadjaj();
	Korisnik(std::string name = "User");
	~Korisnik();
};
