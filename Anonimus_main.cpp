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
	std::string opcija,a,b,c,d,e,f,q;
	a = '1', b = '2', c = '3', d = '4', e = '5', f = '6', q = 'q';
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
		std::getline(std::cin, opcija);
		std::ifstream dog, konf, kat, pitanja, odgovori;
		dog.open("Dogadjaji.txt", std::ios::in);
		konf.open("Konfiguraciona_datoteka.txt", std::ios::in);
		kat.open("Kategorije.txt", std::ios::in);
		pitanja.open("Pitanja.txt", std::ios::in);
		odgovori.open("Odgovori.txt", std::ios::in);
		if (opcija.compare(a)==0)
		{
			std::cout << std::endl;
			korisnik.pregledDanasnjihDogadjaja(konf, dog);
		}
		if (opcija.compare(b) == 0)
		{
			std::cout << std::endl;
			korisnik.pregledBuducihDogadjaja(konf, dog);
		}
		if (opcija.compare(c) == 0)
		{
			std::cout << std::endl;
			korisnik.pregledProslihDogadjaja(konf, dog);
		}
		if (opcija.compare(d) == 0)
		{
			std::cout << std::endl;
			korisnik.pregledPoKategoriji(dog, konf, kat);
		}
		if (opcija.compare(e) == 0)
		{
			std::cout << std::endl;
			korisnik.dodavanjeKomentara();
		}
		if (opcija.compare(f) == 0)
		{
			std::cout << std::endl;
			korisnik.igrajKviz(pitanja, odgovori);
		}
		if (opcija.compare(q) == 0)
			return 0;
		std::cout << std::endl;
	}
	return 0;
}

