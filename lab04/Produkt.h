#include <utility>

#include <utility>

//
// Created by micha on 04.04.2019.
//

#ifndef LAB04_POJAZD_H
#define LAB04_POJAZD_H

#include "Data.h"

namespace lab04 {
    class Produkt {
    public:
        Produkt(const Data &wyprodukowano, std::string nazwa) : wyprodukowano(wyprodukowano), nazwa(std::move(nazwa)) {}

        virtual ~Produkt() = default;

        virtual std::string opis() const;
        virtual double koszt() const = 0;

        virtual bool zapisz(std::ostream &os) const;
        virtual bool wczytaj(std::istream &is);

    protected:
        Data wyprodukowano;
        std::string nazwa;
    };
}
#endif //LAB04_POJAZD_H
