//
// Created by micha on 01.04.2019.
//
#include "obiekty.h"
Osoba::Osoba()
        :imie(""), rok_ur(0) {}

Osoba::Osoba(const string &imie, const int &rok_ur) : imie(imie), rok_ur(rok_ur) {}
std::ostream &operator<<(std::ostream &ost, const Osoba &o) {
    ost<<o.imie<<" "<<o.rok_ur;
    return ost;
}

void Osoba::setImie(const string &imie) {
    Osoba::imie = imie;
}

Grupa::Grupa(int rozmiar): rozmiar(rozmiar), licznik(0){
    cout<<"NORMAL CONSTRUCTOR\n";
    if(rozmiar < 1)
        throw logic_error("Incorrect size of allocating memory");
    else
        tablica = new Osoba[rozmiar];
}

//copy constructor
Grupa::Grupa(const Grupa &grupa) :rozmiar(grupa.rozmiar), licznik(grupa.licznik){
    cout<<"COPY CONSTRUCTOR\n";
    tablica = new Osoba[grupa.rozmiar];
    copy(grupa.tablica,grupa.tablica+rozmiar,tablica);
}

// moving constructor
Grupa::Grupa(Grupa &&grupa)
        :rozmiar(0), licznik(0), tablica(nullptr)
{
    tablica = grupa.tablica;
    licznik=grupa.licznik;
    rozmiar=grupa.rozmiar;
    grupa.tablica = nullptr;
    grupa.licznik=0;
    grupa.rozmiar=0;
}

Grupa &Grupa::operator=(Grupa &&other)
{
    if (this != &other)
    {
        // Free the existing resource.
        delete[] tablica;

        licznik = other.licznik;
        rozmiar = other.rozmiar;
        tablica=other.tablica;

        other.tablica = nullptr;
        other.rozmiar = 0;
        other.licznik=0;
    }
    return *this;
}


Grupa &Grupa::operator=(const Grupa &grupa) {
    cout<<"Free the existing resource\n";
    if (this != &grupa)
    {
        // Free the existing resource.
        delete[] tablica;
        licznik = grupa.licznik;
        rozmiar = grupa.rozmiar;
        tablica = new Osoba[rozmiar];
        copy(grupa.tablica, grupa.tablica + rozmiar, tablica);
    }
    return *this;
}
std::ostream &operator<<(std::ostream &ost, const Grupa &g) {
    ost<<g.licznik<<" "<<g.rozmiar<<endl;
    for(int i =0;i<g.licznik;i++)
    {
        ost<<g.tablica[i]<<endl;
    }
    return ost;
}

void Grupa::add_osoba(const Osoba &osoba) {
    if(licznik>=rozmiar) {
        throw range_error("Too much people! Max size is: "+to_string(licznik));
    }
    tablica[licznik++]=osoba;
}

int Grupa::getLicznik() const {
    return licznik;
}
Grupa::~Grupa(){
    delete [] tablica;
    licznik=0;
    rozmiar=0;
}
