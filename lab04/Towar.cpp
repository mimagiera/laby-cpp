//
// Created by micha on 04.04.2019.
//

#include <sstream>
#include "Towar.h"
namespace lab04 {

    double Towar::koszt() const {
        return cena*(1+vat);
    }

    std::string Towar::opis() const {
        std::stringstream buffer;
        buffer << termin_zdatnosci;
        std::string additional=", Cena: "+std::to_string(cena)+", Vat: "+std::to_string(vat);
        return "Typ: Towar, "+Produkt::opis()+", Termin zdatnosci "+buffer.str()+additional;
    }

    bool Towar::zapisz(std::ostream &os) const {
        if(!Produkt::zapisz(os)) return false;
        os<<"\t";
        if(!termin_zdatnosci.zapisz(os)) return false;
        os<<"\t"<<cena<<"\t"<<vat;
        return os? true: false;
    }

    bool Towar::wczytaj(std::istream &is) {
        if(!Produkt::wczytaj(is)) return false;
        if(!termin_zdatnosci.wczytaj(is)) return false;
        std::string stream;
        std::cin.clear();
        char c;
        int number_of_max_tabs=2;
        int number_of_tabs=0;
        while(is.get(c))
        {
            if(c=='\t')
            {
                number_of_tabs++;
                if(number_of_max_tabs==number_of_tabs) break;
            }
            stream+=c;
        }

        size_t end_index;
        std::string cena_;
        std::string vat_;

        end_index=stream.find('\t');
        if(end_index==std::string::npos) return false;
        cena_=stream.substr(0,end_index);
        stream=stream.substr(end_index+1);
        vat_=stream;


        try {
            cena = std::stod(cena_, nullptr);
            vat=std::stod(vat_);
        }
        catch(std::invalid_argument &argument){
            return false;
        }

        return true;
    }

    Towar::Towar(const Data &wyprodukowano, const std::string &nazwa, double cena, double vat,
                 const Data &termin_zdatnosci) : Produkt(wyprodukowano, nazwa), cena(cena), vat(vat),
                                                 termin_zdatnosci(termin_zdatnosci) {}
}