#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Dogadjaj.h"

class Administrator
{
	private:
		std::string ime="";
		std::string sifra="";
		int provjeraPrijave();//uradjeno
		int prijava();//uradjeno
		void sortirajDogadjaje(std::vector<Dogadjaj>& nizDogadjaja, std::string parametar);//uradjeno
		void citajDogadjaje(std::vector<Dogadjaj>&);//uradjeno
		bool provjeraKategorije(std::string);//uradjeno
		void initDogadjaja();//uradjeno
		std::vector<std::string> split(const std::string& s, char delimiter);//uradjeno
	public:
		Administrator()=default;
		~Administrator();
		void kreirajDogadjaj();//uradjeno
		int urediDogadjaj();
		int pregledDogadjaja();//uradjeno
		int pregledKategorija();//uradjeno
		int dodajKategoriju();
		int obrisiKategoriju();
};

