#include "Dogadjaj.h"
#include "Anonimus.h"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream dat1("Konfiguraciona_datoteka.txt"), dat2("dogadjaji.txt"), dat3("Pitanja.txt"), dat4("Odgovori.txt"),dat5("Kategorije.txt");
	Anonimus a;
	a.igrajKviz(dat3, dat4);
	a.pregledBuducihDogadjaja(dat1, dat2);
	a.pregledBuducihDogadjaja(dat1, dat2); //primjer visestrukog poziva
	a.pregledDanasnjihDogadjaja(dat1, dat2);
	a.pregledProslihDogadjaja(dat1, dat2);
	a.pregledPoKategoriji(dat2, dat1, dat5);
}