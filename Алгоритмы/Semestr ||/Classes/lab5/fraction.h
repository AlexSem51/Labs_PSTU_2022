#ifndef MAIN_CPP_FRACTION_H
#define MAIN_CPP_FRACTION_H
#include "pair.h"

class fraction: public pair{
    //first is numerator, second is denominator
public:
    fraction();
    fraction(int,int);
    fraction(const fraction&);
    ~fraction();
    int get_numerator() const{return getFirst();}
    int get_denominator() const{return getSecond();}
    void set_numerator(int num){ setFirst(num);}
    void set_denominator(int den){ setSecond(den);}
    void operator=(const fraction& frac);
    friend std::istream& operator>>(std::istream &in, fraction& frac);
    friend std::ostream& operator<<(std::ostream &out, fraction& frac);
    bool operator==(fraction frac){ return get_numerator()*frac.get_denominator()==get_denominator()*frac.get_numerator();}
    bool operator>(fraction frac){ return get_numerator()*frac.get_denominator()>get_denominator()*frac.get_numerator();}
    bool operator<(fraction frac){ return !((*this==frac) || (*this>frac));}
    fraction& operator+(fraction& frac);
};

#endif //MAIN_CPP_FRACTION_H
