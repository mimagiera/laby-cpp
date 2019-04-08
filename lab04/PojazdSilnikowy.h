//
// Created by micha on 04.04.2019.
//

#ifndef LAB04_POJAZDSILNIKOWY_H
#define LAB04_POJAZDSILNIKOWY_H
#include "Pojazd.h"
namespace lab04 {
    class PojazdSilnikowy : public Pojazd {
    public:
        PojazdSilnikowy(const Osoba &_wlasciciel, int _przebieg, float pojemnosc, int moc_km);
        float pobierzPojemnosc() { return pojemnosc; }
        std::string opis() const override;
        float mocKW() const override;
        bool zapisz(std::ostream &os) const override;
        bool wczytaj(std::istream &is) override;
    protected:
        float pojemnosc;
        int moc_km;
    };
}
#endif //LAB04_POJAZDSILNIKOWY_H
