#include <iostream>

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

std::ostream &operator<<(std::ostream &ost, const Punkt &p) {
    ost<<p.x<<" "<<p.y;
    return ost;
}



class Macierz{
    double mxx,myy,mxy;

public:
    Macierz(double mxx=0, double mxy=0, double myy=0) : mxx(mxx), mxy(mxy), myy(myy) {}

    Macierz* operator - (Macierz const &macierz)
    {
        mxx-=macierz.mxx;
        mxy-=macierz.mxy;
        myy-=macierz.myy;
        return this;
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

    explicit operator double(){ return wyznacznik();}
};



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