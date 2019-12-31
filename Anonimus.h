#pragma once
#include "Dogadjaj.h"
#include <fstream>
#include <sstream>
#include <vector>

class Anonimus
{
	std::string ime;
public:
	Anonimus();
	void pregledDanasnjihDogadjaja(std::ifstream&, std::ifstream&);
	void pregledPoKategoriji(std::ifstream&, std::ifstream&);
	void pregledBuducihDogadjaja(std::ifstream&, std::ifstream&);
	void pregledProslihDogadjaja(std::ifstream&, std::ifstream&);
	void dodavanjeKomentara(std::fstream);
	void igrajKviz(std::ifstream&, std::ifstream&);
	void pisiDogadjaj(std::vector<std::string>&);
	int brojDogadjaja(std::ifstream&);
	tm& konverzijaDatuma();
	~Anonimus();
};
