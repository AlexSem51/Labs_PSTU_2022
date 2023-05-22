#pragma once
#include <iostream>
#include <map>
using namespace std;

template <class T>
class Set
{
	multimap<int, T> mm;
	int size;
public:
	Set(void);
	Set(int);
	void Print();
	~Set(void);
	T max();
	void add_max(T);
	int min();
	void del_min(int);
	T srednee();
	void summ_srednee(T);
};

template <class T>
Set<T>::Set()
{
	size = 0;
}
template<class T>
Set<T>::~Set()
{
}
template<class T>
Set<T>::Set(int s)
{
	T a;
	for (int i = 1; i <= s; i++)
	{
		cin >> a;
		mm.insert(make_pair(i, a));
	}
	size = mm.size();
}
template<class T>
void Set<T>::Print()
{
	for (auto& e : mm)
	{
		cout << e.first << " : " << e.second << endl;
	}
	cout << endl;
}
template<class T>
T Set<T>::max()
{
	typename multimap<int, T>::iterator i = mm.begin();
	T m = (*i).second;
	while (i != mm.end())
	{
		if (m < (*i).second)
		{
			m = (*i).second;
		}
		i++;
	}
	return m;
}
template<class T>
void Set<T>::add_max(T el)
{
	mm.insert(make_pair(0, el));
}
template<class T>
int Set<T>::min()
{
	typename multimap<int, T>::iterator i = mm.begin();
	int num = 0;
	int k = 0;
	T m = (*i).second;
	while (i != mm.end())
	{
		if (m > (*i).second)
		{
			m = (*i).second;
			num = k;
		}
		i++;
		k++;
	}
	return num;
}
template<class T>
void Set<T>::del_min(int pos)
{
	mm.erase(pos);
}
template<class T>
T Set<T>::srednee()
{
	T s(0, 0);
	int n = 0;
	for (auto& e : mm)
	{
		s = s + e.second;
	}
	n = mm.size();
	return (s / n);
}
template<class T>
void Set<T>::summ_srednee(T el)
{
	for (auto& e : mm)
	{
		e.second = e.second + el;
	}
}