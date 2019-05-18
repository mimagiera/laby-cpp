
//
// Created by micha on 04.04.2019.
//

#ifndef LAB04_OSOBA_H
#define LAB04_OSOBA_H

#include <string>
#include <iostream>
namespace lab04 {
    class Data {
    public:
        Data(int dzien, int miesiac, int rok) : rok(rok), miesiac(miesiac), dzien(dzien) {}

        void ustawRok(const int &r){rok=r;};
        const int &pobierzRok() const {
            return rok;
        }

        bool zapisz(std::ostream &os) const; /// zapisuje atrybuty do strumienia
        bool wczytaj(std::istream &is); /// wczytuje atrybuty ze strumienia
        friend std::ostream &operator<<(std::ostream &ost, const Data &o);

    private:
        int rok;
        int miesiac;
        int dzien;
    };
}
#endif //LAB04_OSOBA_H
