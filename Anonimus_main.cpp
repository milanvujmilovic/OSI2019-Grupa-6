#include "Anonimus.h"
#include "Naslov.h"

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT windowSize = { 0, 0, 150, 24 };
	SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
	SetConsoleTitle(L"EVENT LEADER 2019");
	Sleep(2000);
	std::cout << "=========================================================================================================================\n";
	ascii_art();
	std::cout << "=========================================================================================================================\n";
	Sleep(2000);
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
		{
			std::cout << std::endl;
			korisnik.pregledDanasnjihDogadjaja(konf, dog);
		}
		if (opcija == '2')
		{
			std::cout << std::endl;
			korisnik.pregledBuducihDogadjaja(konf, dog);
		}
		if (opcija == '3')
		{
			std::cout << std::endl;
			korisnik.pregledProslihDogadjaja(konf, dog);
		}
		if (opcija == '4')
		{
			std::cout << std::endl;
			korisnik.pregledPoKategoriji(dog, konf, kat);
		}
		if (opcija == '5')
		{
			std::cout << std::endl;
			//Cekamo da Kljestan zavrsi metodu za dodavanje komentara
			;
		}
		if (opcija == '6')
		{
			std::cout << std::endl;
			korisnik.igrajKviz(pitanja, odgovori);
		}
		if (opcija == 'q')
			return 0;
		std::cout << std::endl;
	}
	return 0;
}

