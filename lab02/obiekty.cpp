//
// Created by micha on 25.03.2019.
//

#include "obiekty.h"
std::ostream &operator<<(std::ostream &ost, const Punkt &p) {
    ost<<p.x<<" "<<p.y;
    return ost;
}

Macierz mnozenie_przez_liczbe(Macierz m, const double liczba)
{
    return {m.mxx*liczba,m.mxy*liczba,m.myy*liczba};
}

void Macierz::zmniejsz_o_1() {
    mxx--;
    mxy--;
    myy--;
}
std::ostream &operator<<(std::ostream &ost, const Macierz &m) {
    ost<<m.mxx<<" "<<m.mxy<<std::endl<<m.mxy<<" "<<m.myy;
    return ost;
}
Punkt punkt_razy_macierz(const Macierz &macierz, const Punkt &punkt) {
    return {punkt.x*macierz.mxx+punkt.y*macierz.mxy,punkt.x*macierz.mxy+punkt.y*macierz.myy};
}
bool Macierz::operator<(Macierz macierz2) {
    return wyznacznik()<macierz2.wyznacznik();
}
double Macierz::wyznacznik() {
    return mxx*myy-mxy*mxy;
}
void Punkt::zmiana_znaku() {
    x*=(-1);
    y*=(-1);
}
double Punkt::operator[](int i) {
    return  (i==0) ?  x : y;
}