#include <iostream>
#include "Osoba.h"
#include "Rower.h"
#include "PojazdSilnikowy.h"
#include "PojazdOsobowy.h"

using namespace lab04;
int main() {
    Osoba osoba("Jan","Kowal",20);
    std::cout<<osoba<<std::endl;
    Rower rower(osoba,12,true);
    std::cout<<rower.opis()<<std::endl;
    PojazdSilnikowy pojazdSilnikowy(osoba,2,2.4f,1);
    std::cout<<pojazdSilnikowy.opis()<<std::endl;
    PojazdOsobowy pojazdOsobowy(osoba,12,1.4f,200,"BMW");
    std::cout<<pojazdOsobowy.opis()<<std::endl;
    return 0;
}