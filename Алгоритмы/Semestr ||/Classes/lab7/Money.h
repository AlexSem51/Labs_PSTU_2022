#pragma once
#include <iostream>
using namespace std;

class Money
{
	long rub;
	int kop;
public:
	Money(void);
	Money(long, int);
	Money(const Money&);
	virtual ~Money(void);
	friend istream& operator>>(istream& in, Money& A);
	friend ostream& operator<<(ostream& out, Money& A);
	Money& operator=(const Money& A);
	Money operator+(Money& A);
};
