#pragma once
#include <iostream>
#include <string>
#include "Dogadjaj.h"
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <sstream>
#include <vector>
#include <algorithm>
#pragma warning(disable : 4996)

class Anonimus
{
	std::string ime;
	std::tm stringToDate(std::string);
public:
	Anonimus();
	void pregledDanasnjihDogadjaja(std::ifstream&, std::ifstream&);
	void pregledPoKategoriji(std::ifstream&, std::ifstream&, std::ifstream&);
	void pregledBuducihDogadjaja(std::ifstream&, std::ifstream&);
	void pregledProslihDogadjaja(std::ifstream&, std::ifstream&);
	void dodavanjeKomentara(std::fstream);
	void igrajKviz(std::ifstream&, std::ifstream&);
	void pisiDogadjaj(std::vector<std::string>&);
	int brojDogadjaja(std::ifstream&);
	tm& konverzijaDatuma();
	~Anonimus();
};

