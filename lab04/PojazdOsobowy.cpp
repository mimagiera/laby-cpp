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

    bool PojazdOsobowy::zapisz(std::ostream &os) const {
        if(!PojazdSilnikowy::zapisz(os)) return false;
        os<<"\t"<<marka;
        return os? true: false;
    }

    bool PojazdOsobowy::wczytaj(std::istream &is) {
        if(!PojazdSilnikowy::wczytaj(is)) return false;
        std::string stream;
        std::cin.clear();
        getline(is, stream);
        marka=stream;
        return true;
    }
}