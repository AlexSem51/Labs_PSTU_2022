#include "fraction.h"
#include "iostream"

fraction::fraction(void):pair() {}

fraction::fraction(int num, int denom): pair(num,denom){}

fraction::fraction(const fraction &frac): pair(frac) {}

fraction::~fraction() {std::cout<<"Deleting fraction "<<getFirst()<<" / "<<getSecond()<<std::endl;}

void fraction::operator=(const fraction &frac){
    set_numerator(frac.get_numerator());
    set_denominator(frac.get_denominator());
}

std::istream& operator>>(std::istream &in,fraction &frac){
    int a,b;
    in>>a>>b;
    frac.set_numerator(a);
    frac.set_denominator(b);
    return in;
}

std::ostream& operator<<(std::ostream &out,fraction &frac) {
    std::cout<<frac.get_numerator()<<" "<<frac.get_denominator();
    return out;
}
