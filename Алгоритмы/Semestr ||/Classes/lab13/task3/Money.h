#pragma once
#include <iostream>
using namespace std;

class Money
{
public:
	long rub;
	int kop;
	Money();
	Money(long, int);
	Money(const Money&);
	~Money();
	long get_rub();
	int get_kop();
	void set_rub(long);
	void set_kop(int);
	friend istream& operator>>(istream& in, Money& A);
	friend ostream& operator<<(ostream& out, const Money& A);
	Money& operator=(const Money&);
	Money operator+(const Money&);
	Money operator/(const int&);
	bool operator>(const Money&) const;
	bool operator<(const Money&) const;
	bool operator==(const Money&);
};