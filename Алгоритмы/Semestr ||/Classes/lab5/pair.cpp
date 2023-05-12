#include "pair.h"
#include "iostream"

pair::pair() {
    first=0;
    second=0;
}

pair::pair(int f, int s) {
    first=f;
    second=s;
}

pair::pair(const pair &p) {
    first=p.first;
    second=p.second;
}

pair::~pair() {std::cout<<"Deleting element "<<first<<" "<<second<<std::endl;}

void pair::operator=(const pair &p) {
    first=p.first;
    second=p.second;
}

std::istream& operator>>(std::istream &in,pair &p) {
    in>>p.first>>p.second;
    return in;
}

std::ostream& operator<<(std::ostream &out,pair &p) {
    std::cout<<p.getFirst()<<" "<<p.getSecond();
    return out;
}
