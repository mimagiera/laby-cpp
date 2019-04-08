#include <iostream>
#include <cstdlib>
#include <ctime>  
#include <cmath>
#include <cstdio>
#include <sstream>
using namespace std;

class Punkt{
        double x,y,z;
        double distanceSquare();
        
    public:
        Punkt();
        Punkt(double x, double y, double z);
        double getZ();
        void changeZ(double newZ);
        bool furtherThan(Punkt p);
        void wypisz();
        static void setLicznik(int nowyLicznik);
        static int licznik;
        void zapisz(ostream &os);
        void wczytaj(istream &os);
        
};

int Punkt::licznik=0;

Punkt::Punkt(){
    x=((double) rand() / (RAND_MAX));
    y=((double) rand() / (RAND_MAX));
    z=((double) rand() / (RAND_MAX));
    licznik++;
}
Punkt::Punkt(double x, double y, double z=1.0)
{
    this->x=x;
    this->y=y;
    this->z=z;
    licznik++;
}
double Punkt::getZ()
{
    return z;
}
void Punkt::changeZ(double newZ)
{
    z=newZ;
}
double Punkt::distanceSquare()
{
    return x*x+y*y+z*z;
}
bool Punkt::furtherThan(Punkt p)
{
    return this->distanceSquare()>p.distanceSquare();
}
void Punkt::wypisz()
{
    cout<<x<<", "<<y<<", "<<z<<endl;
}
void Punkt::setLicznik(int nowyLicznik)
{
    licznik=nowyLicznik;
}

void Punkt::zapisz(ostream &os)
{
    os<<x<<"\t"<<y<<"\t"<<z;
}

void Punkt::wczytaj(istream &os)
{
    //TODO
}

int main()
{
    srand (time(NULL));
    Punkt punkt(12,2,3);
    ostream strean(nullptr);
    stringstream ss;
    punkt.zapisz(ss);
    punkt.wczytaj(ss);
}