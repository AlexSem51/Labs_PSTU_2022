#include<iostream>
#include <vector>
#include <stack>
#include "Money.h"
using namespace std;

typedef stack<Money> st;
typedef vector<Money> vec;

st make_stack(int n)
{
	st s;
	Money m;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		s.push(m);
	}
	return s;
}
st print_stack(st s)
{
	while (!s.empty())
	{
		cout << s.top() << ' ';
		s.pop();
	}
	cout << endl;
	return s;
}
vec copy_stack_to_vector(st s)
{
	vec v;
	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	return v;
}
st copy_vector_to_stack(vec v)
{
	st s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);
	}
	return s;
}
Money& max(st s)
{
	Money m = s.top();
	vec v = copy_stack_to_vector(s);
	while (!s.empty())
	{
		if (s.top() > m) m = s.top();
		s.pop();
	}
	s = copy_vector_to_stack(v);
	return m;
}
void add_max_to_stack(st& s, Money el,int pos)
{
	vec v;
	Money m;
	int i = 0;
	while (!s.empty())
	{
		m = s.top();
		if (i == pos) v.push_back(el);
		v.push_back(m);
		s.pop();
		i++;
	}
	s = copy_vector_to_stack(v);
	v = copy_stack_to_vector(s);
	s = copy_vector_to_stack(v);
}
Money min(st s)
{
	Money m = s.top();
	vec v = copy_stack_to_vector(s);
	while (!s.empty())
	{
		if (s.top() < m) m = s.top();
		s.pop();
	}
	s = copy_vector_to_stack(v);
	return m;
}
void del_min_from_stack(st& s)
{
	Money m = min(s);
	vec v;
	Money tmp;
	while (!s.empty())
	{
		tmp = s.top();
		if (tmp != m) v.push_back(tmp);
		s.pop();
	}
	s = copy_vector_to_stack(v);
}
Money srednee(st s)
{
	vec v = copy_stack_to_vector(s);
	int n = 1;
	Money sum = s.top();
	s.pop();
	while(!s.empty())
	{
		sum = sum + s.top();
		s.pop();
		n++;
	}
	s = copy_vector_to_stack(v);
	return (sum / n);
}
void summ_srednee(st& s, Money el)
{
	vec v;
	Money m;
	while (!s.empty())
	{
		m = s.top();
		v.push_back(m + el);
		s.pop();
	}
	s = copy_vector_to_stack(v);
}

int main4()
{
	Money m;
	st s;
	int n;
	cout << "N?" << endl;
	cin >> n;
	s = make_stack(n);
	print_stack(s);
	Money el = max(s);
	add_max_to_stack(s, el, 0);
	print_stack(s);
	del_min_from_stack(s);
	print_stack(s);
	el = srednee(s);
	summ_srednee(s, el);
	print_stack(s);
	return 0;
}