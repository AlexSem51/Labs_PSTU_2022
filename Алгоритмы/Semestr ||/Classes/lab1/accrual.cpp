#include "accrual.h"

void accrual::Init(double f, unsigned int s) {
    first = f;
    second = s;
}

void accrual::Read() {
    std::cin >> first;
    std::cin >> second;
}

void accrual::Summa() {

        std::cout << (first /30) * second << " rub" << std::endl;
   
}
