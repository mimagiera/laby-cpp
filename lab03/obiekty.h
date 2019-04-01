//
// Created by micha on 01.04.2019.
//

#ifndef LAB03_OBIEKTY_H
#define LAB03_OBIEKTY_H
#include <iostream>
#include <string>
using namespace std;
class Osoba{
private:
    string imie;
    int rok_ur;
public:
    Osoba();

    Osoba(const string &imie, const int &rok_ur);
    friend std::ostream &operator<<(std::ostream &ost, const Osoba &o);

    void setImie(const string &imie);
};

class Grupa{
private:
    int rozmiar;
    int licznik;
    Osoba *tablica;
public:
    Grupa(int rozmiar=20);
    Grupa(const Grupa &grupa);
    Grupa(Grupa &&grupa);
    Grupa& operator =(const Grupa &grupa);
    Grupa& operator =(Grupa &&grupa);
    friend std::ostream &operator<<(std::ostream &ost, const Grupa &g);
    void add_osoba(const Osoba&);

    int getLicznik() const;
    ~Grupa();
};
#endif //LAB03_OBIEKTY_H
