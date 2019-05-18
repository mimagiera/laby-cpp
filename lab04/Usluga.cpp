//
// Created by micha on 04.04.2019.
//

#include "Usluga.h"
namespace lab04 {
    double Usluga::koszt() const {
        return koszt_godziny*ile_godzin;
    }

    std::string Usluga::opis() const {
        return "Typ: Usluga, "+Produkt::opis()+", Koszt godziny: "+std::to_string(koszt_godziny)+", Ilosc godzin: "+std::to_string(ile_godzin);
    }

    bool Usluga::zapisz(std::ostream &os) const {
        if(!Produkt::zapisz(os)) return false;
        os<<"\t"<<koszt_godziny<<"\t"<<ile_godzin;
        return os? true: false;
    }

    bool Usluga::wczytaj(std::istream &is) {
        if(!Produkt::wczytaj(is)) return false;
        std::string stream;
        std::cin.clear();
        getline(is, stream);

        size_t start_index = 0;
        size_t end_index;
        std::string ile_godzin_,koszt_godziny_;
        end_index = stream.find('\t');
        if(end_index==std::string::npos) return false;
        koszt_godziny_ = stream.substr(start_index,end_index);
        stream=stream.substr(end_index+1);

        ile_godzin_ = stream;
        try {
            ile_godzin = std::stod(ile_godzin_);
            koszt_godziny=std::stod(koszt_godziny_);
        }
        catch(std::invalid_argument &argument){
            return false;
        }

        return true;
    }
}
