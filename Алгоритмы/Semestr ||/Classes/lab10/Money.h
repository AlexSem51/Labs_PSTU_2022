#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Money
{
	long rub;
	int kop;
public:
	Money();
	Money(long RUB, int KOP);
	Money(Money& tmp);
	~Money();
	long get_rub();
	int get_kop();
	void set_rub(long RUB);
	void set_kop(int KOP);
	friend istream& operator>>(istream& in, Money& A);
	friend ostream& operator<<(ostream& out, Money& A);
	friend fstream& operator>>(fstream& fin, Money& A);
	friend fstream& operator<<(fstream& fout, Money& A);
	Money& operator=(const Money& A);
	Money operator+(Money& A);
	Money operator-(Money& A);
	bool operator!=(const Money&);
};
