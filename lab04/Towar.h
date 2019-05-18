//
// Created by micha on 04.04.2019.
//

#ifndef LAB04_POJAZDSILNIKOWY_H
#define LAB04_POJAZDSILNIKOWY_H
#include "Produkt.h"
namespace lab04 {
    class Towar : public Produkt {
    public:
        Towar(const Data &wyprodukowano, const std::string &nazwa, double cena, double vat,
              const Data &termin_zdatnosci);
        std::string opis() const override;
        double koszt() const override;
        bool zapisz(std::ostream &os) const override;
        bool wczytaj(std::istream &is) override;

        const Data &pobierzTermin_zdatnosci() const {
            return termin_zdatnosci;
        }

    protected:
        double cena;
        double vat;
        Data termin_zdatnosci;
    };
}
#endif //LAB04_POJAZDSILNIKOWY_H
