#include <iostream>
#include "Money.h"
using namespace std;

Money::Money()
{
	rub = 0;
	kop = 0;
}
Money::Money(long RUB, int KOP)
{
	rub = RUB;
	kop = KOP;
}
Money::Money(const Money& tmp)
{
	rub = tmp.rub;
	kop = tmp.kop;
}
Money::~Money() {};
istream& operator>>(istream& in, Money& A)
{
	cout << "rub?: "; in >> A.rub;
	cout << "kop?: "; in >> A.kop;
	return in;
}
ostream& operator<<(ostream& out, Money& A)
{
	return (out << A.rub << "," << A.kop);
}
Money& Money::operator=(const Money& A)
{
	if (&A == this)
	{
		return *this;
	}
	rub = A.rub;
	kop = A.kop;
	return *this;
}
Money Money::operator+(Money& A)
{
	int tmp1 = rub * 100 + kop;
	int tmp2 = A.rub * 100 + A.kop;
	Money tmp;
	tmp.rub = (tmp1 + tmp2) / 100;
	tmp.kop = (tmp1 + tmp2) % 100;
	return tmp;
}
