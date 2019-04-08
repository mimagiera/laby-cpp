//
// Created by micha on 04.04.2019.
//

#include "PojazdSilnikowy.h"
namespace lab04 {
    PojazdSilnikowy::PojazdSilnikowy(const Osoba &_wlasciciel, int _przebieg, float pojemnosc, int moc_km) : Pojazd(
            _wlasciciel, _przebieg), pojemnosc(pojemnosc), moc_km(moc_km) {}

    float PojazdSilnikowy::mocKW() const {
        return 1.4f * moc_km;
    }

    std::string PojazdSilnikowy::opis() const {
        std::string additional=", Pojemnosc: "+std::to_string(pojemnosc)+", Moc KM: "+std::to_string(moc_km);
        return "Typ: Pojazd silnikowy, "+Pojazd::opis()+additional;
    }

    bool PojazdSilnikowy::zapisz(std::ostream &os) const {
        if(!Pojazd::zapisz(os)) return false;
        os<<"\t"<<pojemnosc<<"\t"<<moc_km;
        return os? true: false;
    }

    bool PojazdSilnikowy::wczytaj(std::istream &is) {
        if(!Pojazd::wczytaj(is)) return false;
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
        size_t start_index = 0;
        size_t end_index;

        std::string pojemnosc_;
        std::string moc_km_;

        end_index = stream.find('\t');
        if(end_index==std::string::npos) return false;
        pojemnosc_ = stream.substr(start_index,end_index);
        stream=stream.substr(end_index+1);

        moc_km_=stream;
        try {
            pojemnosc = std::stof(pojemnosc_, nullptr);
            moc_km=std::stoi(moc_km_);
        }
        catch(std::invalid_argument &argument){
            return false;
        }

        return true;
    }
}