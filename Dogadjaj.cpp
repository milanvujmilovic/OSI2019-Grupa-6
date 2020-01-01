#include "Dogadjaj.h"

void Dogadjaj::operator=(const Dogadjaj& dogadjaj)
{
	this->naziv = dogadjaj.naziv;
	this->datum = dogadjaj.datum;
	this->lokacija = dogadjaj.lokacija;
	this->vrsta = dogadjaj.vrsta;
	this->opis = dogadjaj.opis;
	this->komentari.clear();
	copy(dogadjaj.komentari.begin(), dogadjaj.komentari.end(), back_inserter(this->komentari));
}

Dogadjaj::Dogadjaj(const Dogadjaj& dogadjaj)
{
	this->naziv = dogadjaj.naziv;
	this->vrsta = dogadjaj.vrsta;
	this->lokacija = dogadjaj.lokacija;
	this->datum = dogadjaj.datum;
	this->opis = dogadjaj.opis;
	this->komentari.clear();
	for (auto x : dogadjaj.komentari)
	{
		this->komentari.push_back(x);
	}

}

Dogadjaj::Dogadjaj(Dogadjaj&& dogadjaj)	noexcept
{
	this->naziv = dogadjaj.naziv;
	this->vrsta = dogadjaj.vrsta;
	this->lokacija = dogadjaj.lokacija;
	this->datum = dogadjaj.datum;
	this->opis = dogadjaj.opis;
	this->komentari.clear();
	for (auto x : dogadjaj.komentari)
	{
		this->komentari.push_back(x);
	}
}

void Dogadjaj::upisDogadjaja()
{
	std::ofstream file;
	file.open("Dogadjaji.txt", std::ios::app);
	if (file.is_open())
	{
		file << std::endl;
		file << this->naziv << std::endl;
		file << this->vrsta << std::endl;
		file << this->opis << std::endl;
		file << this->lokacija << std::endl;
		file << this->datum.tm_mday << "." << datum.tm_mon << "." << this->datum.tm_year << "." << "-" << this->datum.tm_hour << ":" << this->datum.tm_min << std::endl;
		file << this->komentari.size();
		for (auto x : this->komentari)
		{
			file << std::endl;
			file << x;
		}
		file.close();
	}
}

void Dogadjaj::izbrisiDogadjaj()
{
	std::string temp;
	int broj;
	std::ifstream ispis;
	ispis.open("Dogadjaji.txt", std::ios::in);
	std::fstream upis;
	upis.open("Temp.txt", std::ios::in | std::ios::out | std::ios::app);
	while (!ispis.eof())
	{
		getline(ispis, temp);
		if (this->naziv == temp)
		{
			getline(ispis, temp);
			getline(ispis, temp);
			getline(ispis, temp);
			getline(ispis, temp);
			getline(ispis, temp);
			broj = std::stoi(temp);
			for (int i = 0; i < broj; i++)
			{
				getline(ispis, temp);

			}
		}
		else
		{
			upis << temp << std::endl;
		}
	}
	ispis.close();
	upis.close();
	remove("Dogadjaji.txt");

	rename("Temp.txt", "Dogadjaji.txt");

}

void Dogadjaj::print()
{
	std::cout << *this;

}

std::ostream& operator<<(std::ostream& stream, const Dogadjaj& other)
{
	stream << "Naziv: " << other.naziv << std::endl;
	stream << "Kategorija: " << other.vrsta << std::endl;
	stream << "Lokacija: " << other.lokacija << std::endl;
	stream << "Opis: " << other.opis << std::endl;
	stream << "Datum: " << other.datum.tm_mday << "." << other.datum.tm_mon << "." << other.datum.tm_year << "." << " " << other.datum.tm_hour << ":" << other.datum.tm_min << std::endl;
	stream << "Komentari: " << std::endl;
	for (unsigned int i = 0; i < other.komentari.size(); ++i)
	{
		stream << other.komentari[i] << std::endl;
	}
	return stream;
}