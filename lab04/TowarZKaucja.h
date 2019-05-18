//
// Created by micha on 04.04.2019.
//

#ifndef LAB04_POJAZDOSOBOWY_H
#define LAB04_POJAZDOSOBOWY_H
#include "Towar.h"
namespace lab04 {
    class TowarZKaucja : public Towar {
    public:
        TowarZKaucja(const Data &wyprodukowano, const std::string &nazwa, double cena, double vat,
                     const Data &termin_zdatnosci, double kaucja) : Towar(wyprodukowano, nazwa, cena, vat,
                                                                          termin_zdatnosci), kaucja(kaucja) {}

        std::string opis() const override;
        double koszt() const override;
        bool zapisz(std::ostream &os) const override;
        bool wczytaj(std::istream &is) override;
    protected:
        double kaucja;
    };
}
#endif //LAB04_POJAZDOSOBOWY_H
