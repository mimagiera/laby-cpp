//
// Created by micha on 04.04.2019.
//

#include "PojazdSilnikowy.h"
namespace lab04 {
    PojazdSilnikowy::PojazdSilnikowy(const Osoba &_wlasciciel, int _przebieg, float pojemnosc, int moc_km) : Pojazd(
            _wlasciciel, _przebieg), pojemnosc(pojemnosc), moc_km(moc_km) {}

    float PojazdSilnikowy::mocKW() const {
        return 1.4f * moc_km;
    }

    std::string PojazdSilnikowy::opis() const {
        std::string additional=", Pojemnosc: "+std::to_string(pojemnosc)+", Moc KM: "+std::to_string(moc_km);
        return "Typ: Pojazd silnikowy, "+Pojazd::opis()+additional;
    }
}