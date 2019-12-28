#define _CRT_SECURE_NO_DEPRECATE
#include "Korisnik.h"



Korisnik::Korisnik(std::string name) :name(name)
{
}

Korisnik::~Korisnik()
{
}

std::tm Korisnik::stringToDate(std::string line)
{
	
	std::tm tmp;
	
	std::string dan;
	std::string mesec;
	std::string godina;
	std::string sat;
	std::string minut;

	

	int i, j, k;
	for (i = 0; line[i]!='.'; i++);
		k = i;
	
		dan = line.substr(0, k);
	
		j = k;
	for (i = k + 1; line[i] != '.'; i++);
		k = i;

		mesec = line.substr(j + 1, k);

		j = k;	
	for (i = k + 1; line[i] != '.'; i++);
		k = i;

		godina = line.substr(j + 1, k);
		
		j = k;
	for (i = k + 1; line[i] != '.'; i++);
		k = i;

		sat = line.substr(j + 1, k);

		j = k;
		
		k = line.size();
		minut = line.substr(j + 1, k);

		

		tmp.tm_mday = std::stoi(dan);
		tmp.tm_mon = std::stoi(mesec);
		tmp.tm_year = std::stoi(godina);
		tmp.tm_hour = std::stoi(sat);
		tmp.tm_min = std::stoi(minut);

	
		return tmp;


}

Dogadjaj Korisnik::ucitajDogadjaj()
{
	std::ifstream myFile(FileName.c_str());
	Dogadjaj d;
	
	std::string tmp;

	getline(myFile, tmp);
	d.setNaziv(tmp);

	getline(myFile, tmp);
	d.setVrsta(tmp);

	getline(myFile, tmp);
	d.setOpis(tmp);

	getline(myFile, tmp);
	d.setLokacija(tmp);

	getline(myFile, tmp);
	std::tm t = stringToDate(tmp);
	d.setDatum(t);
		

	getline(myFile, tmp);
	int brojKomentara = std::stoi(tmp);
	
	for (int i = 0; i < brojKomentara; i++)
	{
		getline(myFile, tmp);
		d.setKomentar(tmp);
	}
	//ispisiDogadjaj(d);

	return d;
}

