

#ifndef MAIN_CPP_PAIR_H
#define MAIN_CPP_PAIR_H
#include "iostream"

class pair{
    int first;
    int second;
public:
    pair();
    pair(int f,int s);
    pair(const pair& p);
    ~pair();
    int getFirst() const{return first;}
    int getSecond() const{return second;}
    void setFirst(int f){first=f;}
    void setSecond(int s){second=s;}
    void operator=(const pair& p);
    friend std::istream& operator>>(std::istream &in, pair& p);
    friend std::ostream& operator<<(std::ostream &out, pair& p);
    bool operator==(pair p){ return first==p.first && second==p.second;}
    bool operator>(pair p){ return (first>p.first || (first==p.first && second>p.second));}
    bool operator<(pair p){ return !((*this==p) || (*this>p));}
};

#endif //MAIN_CPP_PAIR_H
