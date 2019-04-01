#include "obiekty.h"
using namespace std;
int main() {
    Grupa grupa(2);
    Osoba osoba("john",1);
    Osoba osoba1;
    Osoba osoba2;
    osoba.setImie("tom");
    grupa.add_osoba(osoba);
    grupa.add_osoba(osoba1);
    grupa.add_osoba(osoba2);
    Grupa grupa2 = grupa;
    grupa2=grupa;
    cout<<grupa<<endl<<grupa2<<endl;
    Grupa grupa4 = move(grupa2);
    cout<<"*****************\n";
    cout<<grupa4<<endl<<grupa2<<endl;
    return 0;
}