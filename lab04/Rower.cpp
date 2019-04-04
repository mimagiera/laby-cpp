//
// Created by micha on 04.04.2019.
//

#include "Rower.h"
namespace lab04 {
    Rower::Rower(const Osoba &_wlasciciel, int _przebieg, bool amatorski) : Pojazd(_wlasciciel, _przebieg),
                                                                            amatorski(amatorski) {}

    float Rower::mocKW() const {
        return amatorski ? 0.3f : 0.4f;
    }

    std::string Rower::opis() const {
        std::string czyAmatorski = amatorski?"amatorski":"Nie amatorski";
        return "Typ: Rower, "+Pojazd::opis()+", Rodzaj: "+czyAmatorski;
    }
}
