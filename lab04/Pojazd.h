#include <utility>

//
// Created by micha on 04.04.2019.
//

#ifndef LAB04_POJAZD_H
#define LAB04_POJAZD_H

#include "Osoba.h"

namespace lab04 {
    class Pojazd {
    public:
        Pojazd(Osoba _wlasciciel, int _przebieg) : wlasciciel(std::move(_wlasciciel)), przebieg(_przebieg) {}

        virtual ~Pojazd() { delete (&wlasciciel); }

        virtual std::string opis() const; /// zwraca napis z wszystkimi atrybutami (np. "wlasciciel: Jan Kowalski 1970, przebieg: 120000")
        virtual float mocKW() const = 0;

        virtual bool zapisz(std::ostream &os) const;
        virtual bool wczytaj(std::istream &is);

    protected:
        Osoba wlasciciel;
        int przebieg;
    };
}
#endif //LAB04_POJAZD_H
