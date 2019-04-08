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
        std::string czyAmatorski = amatorski?"amatorski":"nie amatorski";
        return "Typ: Rower, "+Pojazd::opis()+", Rodzaj: "+czyAmatorski;
    }

    bool Rower::zapisz(std::ostream &os) const {
        if(!Pojazd::zapisz(os)) return false;
        os<<"\t"<<amatorski;
        return os? true: false;
    }

    bool Rower::wczytaj(std::istream &is) {
        if(!Pojazd::wczytaj(is)) return false;
        std::string stream;
        std::cin.clear();
        getline(is, stream);
        if(stream=="1") amatorski= true;
        else if(stream=="0") amatorski = false;
        else return false;
        return true;
    }
}
