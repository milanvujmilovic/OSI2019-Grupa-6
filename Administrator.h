#pragma once
#include <iostream>
#include <string>
#include "Dogadjaj.h"

class Administrator
{
	private:
		std::string ime="";
		std::string sifra="";

		int provjeraPrijave();
		int prijava();
		void sortirajDogadjaje(std::string);
		bool provjeraKategorije(std::string);
	public:
		Administrator()=default;
		~Administrator();
		int kreirajDogadjaj(std::string,std::string,std::string,std::tm);
		int urediDogadjaj(std::string);
		int pregledDogadjaja();
		int pregledKategorija();
		int dodajKategoriju();
		int obrisiKategoriju();
};

