#include <iostream>
#include <sstream>
#include "Data.h"
#include "Usluga.h"
#include "Towar.h"
#include "TowarZKaucja.h"

using namespace lab04;
int main() {
    Data *data = new Data(12,03,2018);
    Data *data2 = new Data(2,3,1403);
    Produkt *tablica[6];
    tablica[0] = new Usluga(*data,"cos",12,5);
    tablica[1] = new Usluga(*data2,"inne", 16,4);
    tablica[2] = new Towar (*data,"KOT",123,100,*data2);
    tablica[3] = new Towar(*data2,"LEW",180,200,*data);

    tablica[4] = new TowarZKaucja(*data,"SLON",123,1.6f,*data2,12);
    tablica[5] = new TowarZKaucja(*data2,"KONIK",1.8f,1000,*data2,100);

    std::stringstream s1;
    std::cout<<tablica[1]->opis()<<std::endl;
    tablica[0]->zapisz(s1);
    tablica[1]->wczytaj(s1);
    std::cout<<tablica[1]->opis()<<std::endl<<std::endl;

    s1=std::stringstream();
    std::cout<<tablica[3]->opis()<<std::endl;
    tablica[2]->zapisz(s1);
    tablica[3]->wczytaj(s1);
    std::cout<<tablica[3]->opis()<<std::endl<<std::endl;

    s1=std::stringstream();
    std::cout<<tablica[5]->opis()<<std::endl;
    tablica[4]->zapisz(s1);
    tablica[5]->wczytaj(s1);
    std::cout<<tablica[5]->opis()<<std::endl;
    for(int i=0;i<6;i++)
    {
        delete tablica[i];
    }
    return 0;
}