#include "Vector.h"
Vector::Vector() {
    size=0;
    curr=0;
    beg= nullptr;
}
Vector::~Vector(){
    if (beg!= nullptr) delete [] beg;
    beg = nullptr;
}
Vector::Vector(int n) {
    beg = new Object* [n];
    curr=0;
    size=n;
}
void Vector::Add(Object *p) {
    beg[curr]=p;
    curr++;
}
std::ostream& operator<<(std::ostream& out,const Vector& v){
    if(v.size==0) std::cout<<"Empty vector"<<std::endl;
    Object **ptr=v.beg;
    for(int i=0;i<v.curr;i++){
        (*ptr)->Show();
        ptr++;
    }
    return out;
}
