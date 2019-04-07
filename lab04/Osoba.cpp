//
// Created by micha on 04.04.2019.
//

#include <sstream>
#include "Osoba.h"
namespace lab04 {
    std::ostream &operator<<(std::ostream &ost, const Osoba &o) {
        ost << o.imie << "\t" << o.nazwisko << "\t" << o.rok_ur;
        return ost;
    }

    bool Osoba::zapisz(std::ostream &os) const {
        os<< *this;
        return os? true: false;
    }

    bool Osoba::wczytaj(std::istream &is) {
        std::string stream;
        //std::cin.clear();
        getline(is, stream);

        std::string imie_;
        std::string nazwisko_;
        std::string rok_;

        size_t start_index = 0;
        size_t end_index;

        end_index = stream.find('\t');
        if(end_index==std::string::npos) return false;
        imie_ = stream.substr(start_index,end_index);
        stream=stream.substr(end_index+1);

        end_index = stream.find('\t');
        if(end_index==std::string::npos) return false;
        nazwisko_ = stream.substr(start_index,end_index);
        stream=stream.substr(end_index+1);

        rok_ = stream.substr(start_index);


        imie =imie_;
        nazwisko =nazwisko_;
        try {
            rok_ur = std::stoi(rok_);
        }
        catch(std::invalid_argument &argument){
            return false;
        }

        return true;
    }

}
