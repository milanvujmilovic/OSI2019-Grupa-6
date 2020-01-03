#include <iostream>
#include <stdlib.h>
#include "Administrator.h"
using namespace std;

int main()
{
    char opcija;
    Administrator admin;
    while(true){
    std::cout<<"=========================================\n";
    std::cout<<"Izaberite  opciju koju zelite: \n";
    std::cout<<"=========================================\n";
    std::cout<<"1-Pregled dogadjaja\n";
    std::cout<<"2-Pregled kategorija\n";
    std::cout<<"3-Uredi dogadjaj\n";
    std::cout<<"4-Dodaj kategoriju\n";
    std::cout<<"5-Obrisi kategoriju\n";
    std::cout<<"6-Ocisti ekran\n";
    std::cout<<"7-Odjava\n";
    std::cout<<"q-Izadji iz programa\n";
    std::cout<<"=========================================\n";
        std::cin>>opcija;
        std::cin.ignore();
        if(opcija=='1')
        {
            admin.pregledDogadjaja();
        }
        else if(opcija=='2')
        {
            admin.pregledKategorija();
        }
        else if(opcija=='3')
        {
           admin.urediDogadjaj();
        }
        else if(opcija=='4')
        {
            admin.dodajKategoriju();
        }
        else if(opcija=='5')
        {
            admin.obrisiKategoriju();
        }
        else if(opcija=='6')
        {
           system("CLS");
        }
        else if(opcija=='7')
        {
           admin.odjava();
        }
        else if(opcija=='q')
        {
            return 0;
        }
        std::cout<<endl;

    }
    return 0;
}
