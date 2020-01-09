#pragma once
#include "Dogadjaj.h"
#include <stdlib.h>
#include <sstream>
#include <algorithm>

#pragma warning(disable : 4996)

class Anonimus
{
	std::string ime;
	void citajDogadjaje(std::vector<Dogadjaj>&);
	std::vector<std::string> split(const std::string& s, char delimiter);
	std::tm stringToDate(std::string);
public:
	Anonimus();
	void pregledDanasnjihDogadjaja(std::ifstream&, std::ifstream&);
	void pregledPoKategoriji(std::ifstream&, std::ifstream&, std::ifstream&);
	void pregledBuducihDogadjaja(std::ifstream&, std::ifstream&);
	void pregledProslihDogadjaja(std::ifstream&, std::ifstream&);
	void dodavanjeKomentara();
	void igrajKviz(std::ifstream&, std::ifstream&);
	void pisiDogadjaj(std::vector<std::string>&);
	int brojDogadjaja(std::ifstream&);
	tm& konverzijaDatuma();
	~Anonimus();
};