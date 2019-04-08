//
// Created by micha on 04.04.2019.
//

#include <sstream>
#include "Pojazd.h"
namespace lab04 {
    std::string Pojazd::opis() const {
        std::stringstream buffer;
        buffer << wlasciciel;
        std::string opis = "Wlasciciel: " + buffer.str() + ", Przebieg: " + std::to_string(przebieg)+", Moc: "+std::to_string(mocKW())+" kW";
        return opis;
    }

    bool Pojazd::zapisz(std::ostream &os) const {
        if(!wlasciciel.zapisz(os)) return false;
        os<<"\t"<<przebieg;
        return os? true: false;
    }

    bool Pojazd::wczytaj(std::istream &is) {
        unsigned int length_of_word;
        unsigned int total_length=0;
        std::string stream;
        std::cin.clear();
        char c;
        int number_of_max_tabs=4;
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

        std::string stream_copy = stream;

        length_of_word=stream.find('\t');
        if(length_of_word==std::string::npos) return false;
        length_of_word++;
        total_length+=(length_of_word);
        stream=stream.substr(length_of_word);

        length_of_word=stream.find('\t');
        if(length_of_word==std::string::npos) return false;
        length_of_word++;
        total_length+=(length_of_word);
        stream=stream.substr(length_of_word);

        length_of_word=stream.find('\t');
        if(length_of_word==std::string::npos) return false;
        total_length+=(length_of_word);
        stream=stream.substr(length_of_word+1);

        std::string osoba = stream_copy.substr(0,total_length);

        std::stringstream s;

        s<<osoba;

        wlasciciel.wczytaj(s);

        try {
            przebieg = std::stoi(stream);
        }
        catch(std::invalid_argument &argument){
            return false;
        }
        return true;
    }
}