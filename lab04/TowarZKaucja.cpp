//
// Created by micha on 04.04.2019.
//

#include "TowarZKaucja.h"
namespace lab04 {

    std::string TowarZKaucja::opis() const {
        return "Typ: Towar z kaucja, "+ lab04::Towar::opis()+", Kaucja: "+std::to_string(kaucja);
    }

    bool TowarZKaucja::zapisz(std::ostream &os) const {
        if(!Towar::zapisz(os)) return false;
        os<<"\t"<<kaucja;
        return os? true: false;
    }

    bool TowarZKaucja::wczytaj(std::istream &is) {
        if(!Towar::wczytaj(is)) return false;
        std::string stream;
        std::cin.clear();
        getline(is, stream);
        kaucja=stod(stream);
        return true;
    }

    double TowarZKaucja::koszt() const {
        return Towar::koszt()+kaucja;
    }
}