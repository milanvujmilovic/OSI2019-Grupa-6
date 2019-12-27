#include "Administrator.h"
int Administrator::provjeraPrijave()
{
	return 0;
}
int Administrator::prijava()
{
	return 0;
}

void Administrator::sortirajDogadjaje(std::string parametar)
{

}

bool Administrator::provjeraKategorije(std::string nazivKategorije)
{
	/*provjerava da li data kategorije vec postoji na spisku*/
	return false;
}

Administrator::~Administrator()
{

}

int Administrator::kreirajDogadjaj(std::string naziv, std::string vrsta, std::string lokacija, std::tm datum)
{
	Dogadjaj noviDogadjaj{ naziv,vrsta,lokacija,datum };
	/*noviDogadjaj.upisDogadjajUmemoriju();*/
	return 0;
}

int Administrator::urediDogadjaj(std::string naziv)
{
	/*procitaj dogadjaj iz memorije na osnovu imena ili imena i datuma*/
	/*odabir parametara koji se mjenjaju u jednu while(true) petlju staviti da moze da mijenja koliko oce i lupiti q za izlaz*/
	/*update dogadjaja u memoriji*/
	return 0;
}

int Administrator::pregledDogadjaja()
{
	/*for() za ucitavanje svih dogadjaja iz memorije
	u while(true) nuditi mogucnost da sortira dogadjaje koji se pregledaju po nekom parametru datum,naziv,lokacija,kategorija
	*/
	return 0;
}

int Administrator::pregledKategorija()
{
	/*citanje kategorija iz konfiguracionog fajla
	ispis kategorija na std izlaz*/
	return 0;
}

int Administrator::dodajKategoriju()
{
	/*ucitavanje kategorija u memoriju
	provjera da li kategorija vec postoji
	provjera je li osnovna kategorija
	dodavanje kategorije*/
	return 0;
}

int Administrator::obrisiKategoriju()
{
	/*ucitavanje kategorija u memoriju
	provjera da li kategorija vec postoji
	provjera je li osnovna kategorija
	brisanje kategorije
	update svih dogadjaja koji posjeduju tu kategoriju*/
	return 0;
}

