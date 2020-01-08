#include "Dogadjaj.h"
#include "Anonimus.h"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
	Anonimus korisnik;
	char opcija;
	while (true) {
		std::cout << "=========================================\n";
		std::cout << "Izaberite zeljenu opciju:\n";
		std::cout << "=========================================\n";
		std::cout << "1-Pregled danasnjih dogadjaja\n";
		std::cout << "2-Pregled buducih dogadjaja\n";
		std::cout << "3-Pregled proslih dogadjaja\n";
		std::cout << "4-Pregled dogadjaja po kategoriji\n";
		std::cout << "5-Dodaj komentar\n";
		std::cout << "6-Igraj kviz\n";
		std::cout << "q-Izadji iz programa\n";
		std::cout << "=========================================\n";
		std::cin >> opcija;
		std::cin.ignore();
		std::ifstream dog, konf, kat, pitanja, odgovori;
		dog.open("Dogadjaji.txt", std::ios::in);
		konf.open("Konfiguraciona_datoteka.txt", std::ios::in);
		kat.open("Kategorije.txt", std::ios::in);
		pitanja.open("Pitanja.txt", std::ios::in);
		odgovori.open("Odgovori.txt", std::ios::in);
		if (opcija == '1')
			korisnik.pregledDanasnjihDogadjaja(konf, dog);
		if (opcija == '2')
			korisnik.pregledBuducihDogadjaja(konf, dog);
		if (opcija == '3')
			korisnik.pregledProslihDogadjaja(konf, dog);
		if (opcija == '4')
			korisnik.pregledPoKategoriji(dog, konf, kat);
		if (opcija == '5')
			//Cekamo da Kljestan zavrsi metodu za dodavanje komentara
			;
		if (opcija == '6')
			korisnik.igrajKviz(pitanja, odgovori);
		if (opcija == 'q')
			return 0;
		std::cout << std::endl;
	}
	return 0;
}