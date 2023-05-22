#include <iostream>
#include "Set.h"
#include "Error.h"
using namespace std;

Set::Set(int s)
{
	if (s > max_size) { throw MaxSizeError(); }
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = 0;
	}
}
Set::Set(const Set& a)
{
	size = a.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = a.data[i];
	}
}
Set::~Set()
{
	data = 0;
}
Set& Set::operator=(const Set& a)
{
	if (this == &a)
	{
		return *this;
	}
	size = a.size;
	if (data != 0)
	{
		delete[] data;
	}
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = a.data[i];
	}
	return *this;
}
Set Set::operator+(Set& a)
{
	int c = 0;
	int s = size + a.size;
	if (s > max_size) { throw MaxSizeError(); }
	Set tmp(s);
	for (int i = 0; i < size; i++)
	{
		tmp.data[i] = data[i];
	}
	for (int i = size; i < s; i++)
	{
		tmp.data[i] = a.data[c];
		c++;
	}
	return tmp;
}
Set Set::operator++(int t)
{
	if (size + 1 > max_size) { throw MaxSizeError(); }
	Set tmp(size + 1);
	tmp.data[size] = t;
	for (int i = 0; i < size; i++)
	{
		tmp.data[i] = data[i];
	}
	data = tmp.data;
	size = tmp.size;
	return tmp;
}
int Set::operator()()
{
	return size;
}
int& Set::operator[](int index)
{
	if (index < 0) { throw IndexError0(); }
	if (index >= size) { throw IndexErrorS(); }
	if (index < size)
	{
		return data[index];
	}
}
istream& operator>>(istream& in, Set& a)
{
	for (int i = 0; i < a.size; i++)
	{
		in >> a.data[i];
	}
	return in;
}
ostream& operator<<(ostream& out, const Set& a)
{
	for (int i = 0; i < a.size; i++)
	{
		out << a.data[i] << ' ';
	}
	return out;
}

