//
// Created by micha on 04.04.2019.
//

#ifndef LAB04_ROWER_H
#define LAB04_ROWER_H

#include "Pojazd.h"

namespace lab04 {
    class Rower : public Pojazd {
    public:
        Rower(const Osoba &_wlasciciel, int _przebieg, bool amatorski);
        std::string opis() const override;
        float mocKW() const override;
        bool zapisz(std::ostream &os) const override;
        bool wczytaj(std::istream &is) override;

    protected:
        bool amatorski;
    };
}
#endif //LAB04_ROWER_H
