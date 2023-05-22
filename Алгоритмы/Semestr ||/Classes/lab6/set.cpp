#include <iostream>
#include "Set.h"

Set::Set(int s)
{
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = 0;
	}
	beg.elem = &data[0];
	end.elem = &data[size];
}

Set::Set(const Set& a)
{
	size = a.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{	
		data[i] = a.data[i];
	}
	beg = a.beg;
	end = a.end;
}

Set::~Set()
{
	delete[] data;
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
	beg = a.beg;
	end = a.end;
	return *this;
}

int& Set::operator[](int index)
{
	if (index < size)
	{
		return data[index];
	}
	else
	{
		std::cout << "Error" << std::endl;
	}
}

Set Set::operator+(Set& a)
{
	int c = 0;
	int s = size + a.size;
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

int Set::operator()()
{
	return size;
}

std::istream& operator>>(std::istream& in, Set& a)
{
	for (int i = 0; i < a.size; i++)
	{
		in >> a.data[i];
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Set& a)
{
	for (int i = 0; i < a.size; i++)
	{
		out << a.data[i] << ' ';
	}
	return out;
}
