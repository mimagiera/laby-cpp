//
// Created by micha on 04.04.2019.
//

#include <sstream>
#include "Produkt.h"
namespace lab04 {
    std::string Produkt::opis() const {
        std::stringstream buffer;
        buffer << wyprodukowano;
        std::string opis = "Data produkcji: " + buffer.str() + ", Nazwa: " + nazwa+", Koszt: "+std::to_string(
                koszt());
        return opis;
    }

    bool Produkt::zapisz(std::ostream &os) const {
        if(!wyprodukowano.zapisz(os)) return false;
        os<<"\t"<<nazwa;
        return os? true: false;
    }

    bool Produkt::wczytaj(std::istream &is) {
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

        std::string data_produkcji = stream_copy.substr(0,total_length);

        std::stringstream s;

        s<<data_produkcji;

        wyprodukowano.wczytaj(s);

        try {
            nazwa = stream;
        }
        catch(std::invalid_argument &argument){
            return false;
        }
        return true;
    }
}