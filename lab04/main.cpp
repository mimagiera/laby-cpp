#include <iostream>
#include <sstream>
#include "Osoba.h"
#include "Rower.h"
#include "PojazdSilnikowy.h"
#include "PojazdOsobowy.h"

using namespace lab04;
int main() {
    Osoba osoba("Janeczek","Kowalski",20);
    Osoba osoba2("Jan","Nowiutki",45);
    //std::cout<<osoba<<std::endl;
    Rower rower(osoba,12,true);
    Rower rower2(osoba2,156,true);
    /*std::cout<<rower.opis()<<std::endl;
    PojazdSilnikowy pojazdSilnikowy(osoba,2,2.4f,1);
    std::cout<<pojazdSilnikowy.opis()<<std::endl;
    PojazdOsobowy pojazdOsobowy(osoba,12,1.4f,200,"BMW");
    std::cout<<pojazdOsobowy.opis()<<std::endl;*/
    /*std::stringstream s;
    osoba.zapisz(s);
    std::cout<<osoba2<<std::endl;
    osoba2.wczytaj(s);
    std::cout<<osoba2<<std::endl;
    std::stoi("12");*/
    std::stringstream s2;
    rower.zapisz(s2);
    std::cout<<rower2.opis()<<std::endl;
    rower2.wczytaj(s2);
    std::cout<<rower2.opis()<<std::endl;

    return 0;
}