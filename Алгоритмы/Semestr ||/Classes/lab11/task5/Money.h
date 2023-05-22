#pragma once
#include <iostream>
using namespace std;

class Money
{
	long rub;
	int kop;
public:
	Money();
	Money(long, int);
	Money(const Money&);
	~Money();
	long get_rub();
	int get_kop();
	void set_rub(long);
	void set_kop(int);
	friend istream& operator>>(istream& in, Money& A);
	friend ostream& operator<<(ostream& out, Money& A);
	Money& operator=(const Money&);
	Money operator+(Money&);
	Money operator/(const int&);
	bool operator>(const Money&);
	bool operator<(const Money&);
	bool operator!=(const Money&);
};