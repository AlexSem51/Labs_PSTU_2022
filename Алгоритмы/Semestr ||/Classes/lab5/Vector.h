#ifndef MAIN_CPP_VECTOR_H
#define MAIN_CPP_VECTOR_H
#include "Object.h"
#include <iostream>
#include <cstring>

class Vector{
    int size;
    int curr;
    Object** beg;
public:
    Vector();
    Vector(int n);
    ~Vector();
    void Add(Object* );
    friend std::ostream& operator<<(std::ostream& out,const Vector&);

};


#endif //MAIN_CPP_VECTOR_H
