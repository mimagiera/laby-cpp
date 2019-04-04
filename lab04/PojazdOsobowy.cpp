//
// Created by micha on 04.04.2019.
//

#include "PojazdOsobowy.h"
namespace lab04 {
    PojazdOsobowy::PojazdOsobowy(const Osoba &_wlasciciel, int _przebieg, float pojemnosc, int moc_km,
                                 const std::string &marka) : PojazdSilnikowy(_wlasciciel, _przebieg, pojemnosc, moc_km),
                                                             marka(marka) {}

    std::string PojazdOsobowy::opis() const {
        std::string additional=", Pojemnosc: "+std::to_string(pojemnosc)+", Moc KM: "+std::to_string(moc_km);
        return "Typ: Pojazd osobowy, "+Pojazd::opis()+additional+", Marka: "+marka;
    }
}