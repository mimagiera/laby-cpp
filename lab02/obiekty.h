//
// Created by micha on 25.03.2019.
//
#include <iostream>
#ifndef LAB02_OBIEKTY_H
#define LAB02_OBIEKTY_H

class Macierz;
class Punkt{
    private:
        double x,y;
    public:
        Punkt(double x=0, double y=0) : x(x), y(y) {}
        friend std::ostream& operator<<(std::ostream& ost,const Punkt &p);
        friend Punkt punkt_razy_macierz(const Macierz &macierz, const Punkt &punkt);
        void zmiana_znaku();
        double operator [] (int i);
};
class Macierz{
    double mxx,myy,mxy;

public:
    Macierz(double mxx=0, double mxy=0, double myy=0) : mxx(mxx), mxy(mxy), myy(myy) {}

    Macierz operator - (Macierz const &macierz)
    {
        return {mxx-macierz.mxx,mxy-macierz.mxy,myy-macierz.myy};
    }
    Macierz* operator -= (Macierz const &macierz)
    {
        mxx-=macierz.mxx;
        mxy-=macierz.mxy;
        myy-=macierz.myy;
        return this;
    }

    void zmniejsz_o_1();
    friend Macierz mnozenie_przez_liczbe(Macierz m, double liczba);
    friend std::ostream& operator<<(std::ostream& ost,const Macierz &m);
    friend Punkt punkt_razy_macierz(const Macierz &macierz, const Punkt &punkt);
    bool operator<(Macierz macierz2);
    double wyznacznik();

    operator double(){ return wyznacznik();}
};

#endif //LAB02_OBIEKTY_H
