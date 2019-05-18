//
// Created by micha on 04.04.2019.
//

#ifndef LAB04_ROWER_H
#define LAB04_ROWER_H

#include "Produkt.h"
#include "Data.h"

namespace lab04 {
    class Usluga : public Produkt {
    public:
        Usluga(const Data &wyprodukowano, const std::string &nazwa, double koszt_godziny, double ile_godzin) : Produkt(
                wyprodukowano, nazwa), koszt_godziny(koszt_godziny), ile_godzin(ile_godzin) {}

        std::string opis() const override;
        double koszt() const override;
        bool zapisz(std::ostream &os) const override;
        bool wczytaj(std::istream &is) override;

    protected:
        double koszt_godziny;
        double ile_godzin;
    };
}
#endif //LAB04_ROWER_H
