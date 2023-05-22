#pragma once
#include <iostream>
using namespace std;

const int max_size = 5;

class Set
{
	int size;
	int* data;
public:
	Set(int);
	Set(const Set&);
	~Set();
	Set& operator=(const Set&);
	Set operator+(Set&);
	Set operator++(int);
	int operator()();
	int& operator[](int);
	friend istream& operator>> (istream& in, Set& a);
	friend ostream& operator<< (ostream& out, const Set& a);
};
