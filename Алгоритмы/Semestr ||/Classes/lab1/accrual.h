
//
// Created by 1 on 19.04.2023.
//

#ifndef MAIN_CPP_RATIONAL_H
#define MAIN_CPP_RATIONAL_H

#include "iostream"

class accrual {
    float first;
    unsigned int second;
public:
    void Init(double f, unsigned int s);

    void Read();

    void Show() { std::cout << "salary: " <<  first << ";" << " Number of days worked:" << " " << second << std::endl; }


    void Summa();
};

#endif //MAIN_CPP_RATIONAL_H#pragma once
