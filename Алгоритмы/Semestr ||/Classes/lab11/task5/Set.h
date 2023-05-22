#pragma once
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template <class T>
class Set
{
	stack <T> st;
	int size;
public:
	Set(void);
	Set(int);
	Set(const Set<T>&);
	void Print();
	~Set(void);
	T& max();
	void add_max_to_stack(T,int);
	T min();
	void del_min_from_stack();
	T srednee();
	void summ_srednee(T);
};

template <class T>
vector<T> copy_stack_to_vector(stack<T> st)
{
	vector<T> v;
	while (!st.empty())
	{
		v.push_back(st.top());
		st.pop();
	}
	return v;
}
template <class T>
stack<T> copy_vector_to_stack(vector<T> v)
{
	stack<T> st;
	for (int i = 0; i < v.size(); i++)
	{
		st.push(v[i]);
	}
	return st;
}

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
		st.push(a);
	}
	size = st.size();
}
template<class T>
void Set<T>::Print()
{
	vector<T> v = copy_stack_to_vector(st);
	while (!st.empty())
	{
		cout << st.top() << ' ';
		st.pop();
	}
	cout << endl;
	st = copy_vector_to_stack(v);
}
template<class T>
Set<T>::Set(const Set<T>& set)
{
	size = set.size;
	vector v = copy_stack_to_vector(set.st);
	st = copy_vector_to_stack(v);
}
template<class T>
T& Set<T>::max()
{
	T m = st.top();
	vector<T> v = copy_stack_to_vector(st);
	while (!st.empty())
	{
		if (st.top() > m) m = st.top();
		st.pop();
	}
	st = copy_vector_to_stack(v);
	return m;
}
template<class T>
void Set<T>::add_max_to_stack(T el,int pos)
{
	vector<T> v;
	T m;
	int i = 0;
	while (!st.empty())
	{
		m = st.top();
		if (i == pos) v.push_back(el);
		v.push_back(m);
		st.pop();
		i++;
	}
	st = copy_vector_to_stack(v);
	v = copy_stack_to_vector(st);
	st = copy_vector_to_stack(v);
}
template<class T>
T Set<T>::min()
{
	T m = st.top();
	vector<T> v = copy_stack_to_vector(st);
	while (!st.empty())
	{
		if (st.top() < m) m = st.top();
		st.pop();
	}
	st = copy_vector_to_stack(v);
	return m;
}
template<class T>
void Set<T>::del_min_from_stack()
{
	T m = min();
	vector<T> v;
	T tmp;
	while (!st.empty())
	{
		tmp = st.top();
		if (tmp != m) v.push_back(tmp);
		st.pop();
	}
	st = copy_vector_to_stack(v);
}
template<class T>
T Set<T>::srednee()
{
	vector<T> v = copy_stack_to_vector(st);
	int n = 1;
	T sum = st.top();
	st.pop();
	while (!st.empty())
	{
		sum = sum + st.top();
		st.pop();
		n++;
	}
	st = copy_vector_to_stack(v);
	return (sum / n);
}
template<class T>
void Set<T>::summ_srednee(T el)
{
	vector<T> v;
	T m;
	while (!st.empty())
	{
		m = st.top();
		v.push_back(m + el);
		st.pop();
	}
	st = copy_vector_to_stack(v);
}