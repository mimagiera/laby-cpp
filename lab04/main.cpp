#include <iostream>
#include <sstream>
#include "Osoba.h"
#include "Rower.h"
#include "PojazdSilnikowy.h"
#include "PojazdOsobowy.h"

using namespace lab04;
int main() {
    Osoba *osoba = new Osoba("Janeczek","Kowalski",2000);
    Osoba *osoba2 = new Osoba("Jan","Nowiutki",1980);
    Pojazd *tablica[6];
    tablica[0] = new Rower(*osoba,12,true);
    tablica[1] = new Rower(*osoba2,156, false);
    tablica[2] = new PojazdSilnikowy (*osoba,123,1.6f,100);
    tablica[3] = new PojazdSilnikowy(*osoba2,20000,1.8f,200);
    tablica[4] = new PojazdOsobowy(*osoba,123,1.6f,100,"BMW");
    tablica[5] = new PojazdOsobowy(*osoba2,2000,1.8f,1000,"MERCEDES");

    std::stringstream s1;
    std::cout<<tablica[1]->opis()<<std::endl;
    tablica[0]->zapisz(s1);
    tablica[1]->wczytaj(s1);
    std::cout<<tablica[1]->opis()<<std::endl<<std::endl;

    s1=std::stringstream();
    std::cout<<tablica[3]->opis()<<std::endl;
    tablica[2]->zapisz(s1);
    tablica[3]->wczytaj(s1);
    std::cout<<tablica[3]->opis()<<std::endl<<std::endl;

    s1=std::stringstream();
    std::cout<<tablica[5]->opis()<<std::endl;
    tablica[4]->zapisz(s1);
    tablica[5]->wczytaj(s1);
    std::cout<<tablica[5]->opis()<<std::endl;
    return 0;
}