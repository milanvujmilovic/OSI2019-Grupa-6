#pragma once
#include <iostream>
#include <string>
#include "Dogadjaj.h"
#include <fstream>

class Anonimus
{
	std::string ime;
public:
	Anonimus();
	void pregledDanasnjihDogadjaja(std::ifstream);
	void pregledPoKategoriji(std::ifstream);
	void pregledBuducihDogadjaja(std::ifstream);
	void pregledProslihDogadjaja(std::ifstream);
	void dodavanjeKomentara(std::fstream);
	void igrajKviz(std::fstream&, std::fstream&);
	~Anonimus();
};

