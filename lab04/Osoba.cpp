//
// Created by micha on 04.04.2019.
//

#include "Osoba.h"
namespace lab04 {
    std::ostream &operator<<(std::ostream &ost, const Osoba &o) {
        ost << o.imie << " " << o.nazwisko << " " << o.rok_ur;
        return ost;
    }
}
