//
// Created by micha on 04.04.2019.
//

#include <sstream>
#include "Data.h"
namespace lab04 {
    std::ostream &operator<<(std::ostream &ost, const Data &o) {
        ost << o.dzien << "\t" << o.miesiac << "\t" << o.rok;
        return ost;
    }

    bool Data::zapisz(std::ostream &os) const {
        os<< *this;
        return (bool)os;
    }

    bool Data::wczytaj(std::istream &is) {
        std::string stream;
        std::cin.clear();

        char c;
        int number_of_max_tabs=3;
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

        std::string rok_;
        std::string miesiac_;
        std::string dzien_;

        size_t start_index = 0;
        size_t end_index;

        end_index = stream.find('\t');
        if(end_index==std::string::npos) return false;
        dzien_ = stream.substr(start_index,end_index);
        stream=stream.substr(end_index+1);

        end_index = stream.find('\t');
        if(end_index==std::string::npos) return false;
        miesiac_ = stream.substr(start_index,end_index);
        stream=stream.substr(end_index+1);

        rok_ = stream;

        try {
            dzien = std::stoi(dzien_);
            rok=std::stoi(rok_);
            miesiac=std::stoi(miesiac_);
        }
        catch(std::invalid_argument &argument){
            return false;
        }

        return true;
    }


}
