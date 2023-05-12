#include "fraction.h"
#include "pair.h"

void f1(pair& p){
    p.setFirst(-19);
    std::cout<<p;
}

pair f2(){
    fraction frac(23,45);
    return frac;
}

int main(){
    pair p1;
    std::cin>>p1;
    std::cout<<p1;
    pair p2(2,5);
    std::cout<<p2;
    p1=p2;
    std::cout<<p2;
    fraction f;
    std::cin>>f;
    std::cout<<f;
    f1(f);
    p1 = f2();
    std::cout<<p1;
    return 0;
}
