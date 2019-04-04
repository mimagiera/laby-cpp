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
}