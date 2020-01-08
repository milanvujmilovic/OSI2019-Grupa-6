#include <iostream>
#include <stdlib.h>
#include "Administrator.h"
#include "Anonimus.h"

using namespace std;

int main()
{
    char opcija,op;
    Administrator admin;
	Anonimus korisnik;
	while (true) {
		std::cout << "=========================================\n";
		std::cout << "Izaberite tip korisnika:\n";
		std::cout << "=========================================\n";
		std::cout << "1-Administrator\n";
		std::cout << "2-Korisnik\n";
		std::cout << "q-Izadji iz programa\n";
		std::cout << "=========================================\n";
		std::cin >> op;
		std::cin.ignore();
		if (op == '1') {
			while (true) {
				std::cout << "=========================================\n";
				std::cout << "Izaberite  opciju koju zelite: \n";
				std::cout << "=========================================\n";
				std::cout << "1-Pregled dogadjaja\n";
				std::cout << "2-Pregled kategorija\n";
				std::cout << "3-Uredi dogadjaj\n";
				std::cout << "4-Dodaj kategoriju\n";
				std::cout << "5-Obrisi kategoriju\n";
				std::cout << "6-Ocisti ekran\n";
				std::cout << "7-Odjava\n";
				std::cout << "q-Izadji iz programa\n";
				std::cout << "=========================================\n";
				std::cin >> opcija;
				std::cin.ignore();
				if (opcija == '1')
				{
					admin.pregledDogadjaja();
				}
				else if (opcija == '2')
				{
					admin.pregledKategorija();
				}
				else if (opcija == '3')
				{
					admin.urediDogadjaj();
				}
				else if (opcija == '4')
				{
					admin.dodajKategoriju();
				}
				else if (opcija == '5')
				{
					admin.obrisiKategoriju();
				}
				else if (opcija == '6')
				{
					system("CLS");
				}
				else if (opcija == '7')
				{
					admin.odjava();
				}
				else if (opcija == 'q')
				{
					return 0;
				}
				std::cout << endl;

			}
		}
		if (op == '2') {
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
					korisnik.pregledDanasnjihDogadjaja(konf,dog);
				if (opcija == '2')
					korisnik.pregledBuducihDogadjaja(konf,dog);
				if (opcija == '3')
					korisnik.pregledProslihDogadjaja(konf,dog);
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
		}
		if (op == 'q')
			return 0;
	}
    return 0;
}
