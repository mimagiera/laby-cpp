#include <iostream>
#include "obiekty.h"
int main() {
    Punkt punkt(1,2);
    Macierz macierz1(3,3,3);
    Macierz macierz2(1,1,1);

    macierz1-=macierz2;
    std::cout<<macierz1;
    macierz1=mnozenie_przez_liczbe(macierz1,1);
    punkt=punkt_razy_macierz(macierz1,punkt);
    macierz1.zmniejsz_o_1();
    punkt.zmiana_znaku();
    return 0;
}