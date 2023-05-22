#include <iostream>
#include <vector>
#include <algorithm>
#include "Money.h"
using namespace std;

typedef vector<Money>  vec;
Money s;
Money p;

vec make_vector(int n)
{
	vec v;
	Money a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	return v;
}
void print_vector(vec v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ' ';
	}
	cout << endl;
}
struct Equal_s
{
	bool operator()(Money t)
	{
		return t == s;
	}
};
Money srednee(vec v)
{
	Money s = v[0];
	int n = v.size();
	for (int i = 1; i < v.size(); i++)
	{
		s = s + v[i];
	}
	return (s / n);
}
void summ_srednee(Money& el)
{
	el = el + p;
}


int main1()
{
	int n;
	cout << "N?" << endl;
	cin >> n;
	vec v;
	v = make_vector(n);
	print_vector(v);
	vec::iterator i;
	i = max_element(v.begin(), v.end());
	cout << "max = " << (*i) << endl;
	Money max = (*i);
	v.insert(v.begin(),max);
	print_vector(v);
	i = min_element(v.begin(), v.end());
	cout << "min = " << (*i) << endl;
	s = (*i);
	v.erase(remove_if(v.begin(), v.end(), Equal_s()), v.end());
	print_vector(v);
	p = srednee(v);
	for_each(v.begin(), v.end(), summ_srednee);
	print_vector(v);
	return 0;
}