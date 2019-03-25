#include <iostream>
#include "obiekty.h"
int main() {
    Punkt punkt(1,2);
    Macierz macierz1(3,3,3);
    Macierz macierz2(1,1,1);
    Macierz macierz3;

    macierz3=macierz1-macierz2;
    std::cout<<macierz1;
    return 0;
}