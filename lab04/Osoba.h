//
// Created by micha on 04.04.2019.
//

#ifndef LAB04_OSOBA_H
#define LAB04_OSOBA_H

#include <string>
#include <iostream>
namespace lab04 {
    class Osoba {
    public:
        Osoba(const std::string &imie, const std::string &nazwisko, int rok_ur) : imie(imie), nazwisko(nazwisko),
                                                                                  rok_ur(rok_ur) {}

        void ustawImie(const std::string &im) { imie = im; }

        std::string pobierzImie() const { return imie; }


        bool zapisz(std::ostream &os) const; /// zapisuje atrybuty do strumienia
        bool wczytaj(std::istream &is); /// wczytuje atrybuty ze strumienia
        friend std::ostream &operator<<(std::ostream &ost, const Osoba &o);

    private:
        std::string imie;
        std::string nazwisko;
        int rok_ur;
    };
}
#endif //LAB04_OSOBA_H
