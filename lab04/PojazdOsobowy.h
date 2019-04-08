//
// Created by micha on 04.04.2019.
//

#ifndef LAB04_POJAZDOSOBOWY_H
#define LAB04_POJAZDOSOBOWY_H
#include "PojazdSilnikowy.h"
namespace lab04 {
    class PojazdOsobowy : public PojazdSilnikowy {
    public:
        PojazdOsobowy(const Osoba &_wlasciciel, int _przebieg, float pojemnosc, int moc_km, const std::string &marka);
        std::string opis() const override;
        bool zapisz(std::ostream &os) const override;
        bool wczytaj(std::istream &is) override;
    protected:
        std::string marka;
    };
}
#endif //LAB04_POJAZDOSOBOWY_H
