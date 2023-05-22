#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Set
{
	vector <T> vec;
	int size;
public:
	Set(void);
	Set(int);
	void Print();
	~Set(void);
	T& max();
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
	for (int i = 0; i < s; i++)
	{
		cin >> a;
		vec.push_back(a);
	}
	size = vec.size();
}
template<class T>
void Set<T>::Print()
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << ' ';
	}
	cout << endl;
}
template<class T>
T& Set<T>::max()
{
	T m = vec[0];
	for (int i = 0; i < vec.size(); i++)
	{
		if (m < vec[i])
		{
			m = vec[i];
		}
	}
	return m;
}
template<class T>
void Set<T>::add_max(T el)
{
	vec.insert(vec.begin(), el);
}
template<class T>
int Set<T>::min()
{
	T m = vec[0];
	int n = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (m > vec[i])
		{
			m = vec[i];
			n = i;
		}
	}
	return n;
}
template<class T>
void Set<T>::del_min(int pos)
{
	vec.erase(vec.begin() + pos);
}
template<class T>
T Set<T>::srednee()
{
	T s = vec[0];
	int n = vec.size();
	for (int i = 1; i < vec.size(); i++)
	{
		s = s + vec[i];
	}
	return (s/n);
}
template<class T>
void Set<T>::summ_srednee(T el)
{
	for (int i = 0; i < vec.size(); i++)
	{
		vec[i] = vec[i] + el;
	}
}

