#include "Administrator.h"
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
    char opcija;
    Administrator s;
    while(true){
    std::cout<<"=========================================================================================================================\n";
    std::cout<<"Izaberite  zeljenu opciju: \n";
    std::cout<<"=========================================================================================================================\n";
    std::cout<<"0-Prijava\n";
    std::cout<<"1-Kreiraj dogadjaj\n";
    std::cout<<"2-Brisanje dogadjaja\n";
    std::cout<<"3-Pregled dogadjaja\n";
    std::cout<<"4-Pregled kategorija\n";
    std::cout<<"5-Uredi dogadjaj\n";
    std::cout<<"6-Dodaj kategoriju\n";
    std::cout<<"7-Obrisi kategoriju\n";
    std::cout<<"8-Ocisti ekran\n";
    std::cout<<"9-Odjava\n";
    std::cout<<"q-Izadji iz programa\n";
    std::cout<<"=========================================================================================================================\n";
        std::cin>>opcija;
        std::cin.ignore();
         if(opcija=='0')
        {
            if(s.provjeraPrijave())
            s.prijava();
            else
            std::cout<<"Vec ste prijavljeni na sistem\n";
        }
        else if(opcija=='1')
        {
            s.kreirajDogadjaj();
        }
        else if(opcija=='2')
        {
            s.brisiDogadjaj();
        }
         else if(opcija=='3')
        {
            s.pregledDogadjaja();
        }
        else if(opcija=='4')
        {
            s.pregledKategorija();
        }
        else if(opcija=='5')
        {
           s.urediDogadjaj();
        }
        else if(opcija=='6')
        {
            s.dodajKategoriju();
        }
        else if(opcija=='7')
        {
            s.obrisiKategoriju();
        }
        else if(opcija=='8')
        {
           system("CLS");
        }
        else if(opcija=='9')
        {
           s.odjava();
        }
        else if(opcija=='q')
        {
            return 0;
        }
        std::cout<<std::endl;

    }
    return 0;
}

