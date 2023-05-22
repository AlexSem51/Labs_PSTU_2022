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
long Money::get_rub()
{
	return rub;
}
int Money::get_kop()
{
	return kop;
}
void Money::set_rub(long RUB)
{
	rub = RUB;
}
void Money::set_kop(int KOP)
{
	kop = KOP;
}
istream& operator>>(istream& in, Money& A)
{
	cout << "rub?: "; in >> A.rub;
	cout << "kop?: "; in >> A.kop;
	return in;
}
ostream& operator<<(ostream& out, const Money& A)
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
Money Money::operator/(const int& t)
{
	int tmp = rub * 100 + kop;
	Money m;
	m.rub = (tmp / t) / 100;
	m.kop = (tmp / t) % 100;
	return m;
}
bool Money::operator>(const Money& A)
{
	if (rub > A.rub) return true;
	if (rub == A.rub && kop > A.kop) return true;
	return false;
}
bool Money::operator<(const Money& A) 
{
	if (rub < A.rub) return true;
	if (rub == A.rub && kop < A.kop) return true;
	return false;
}
bool Money::operator==(const Money& A) 
{
	if (rub == A.rub && kop == A.kop)
	{
		return true;
	}
	return false;
}