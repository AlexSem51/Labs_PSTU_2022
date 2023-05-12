#include "Object.h"
#include "fraction.h"
#include "pair.h"
#include "Vector.h"
#include <string>
#include <iostream>
int main(){
    Vector v(5);
    pair just_another_pair;
    std::cin>>just_another_pair;
    fraction this_is_another_fraction_problems_with_naming;
    std::cin>>this_is_another_fraction_problems_with_naming;
    Object* ptr = &just_another_pair;
    v.Add(ptr);
    ptr = &this_is_another_fraction_problems_with_naming;
    v.Add(ptr);
    std::cout<<v;
    return 0;
}
