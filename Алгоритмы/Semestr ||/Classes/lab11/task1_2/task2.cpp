#include <iostream>
#include <vector>
#include "Money.h"
using namespace std;

typedef vector<Money> vec;

vec make_vector(int n)
{
	vec v;
	for (int i = 0; i < n; i++)
	{
		Money a(rand() % 100, rand() % 100);
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
Money& max(vec v)
{
	Money m = v[0];
	for (int i = 0; i < v.size(); i++)
	{
		if (m < v[i])
		{
			m = v[i];
		}
	}
	return m;
}
void add_max(vec& v, Money el)
{
	v.insert(v.begin(), el);
}
int min(vec v)
{
	Money m = v[0];
	int n = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (m > v[i])
		{
			m = v[i];
			n = i;
		}
	}
	return n;
}
void del_min(vec& v, int pos)
{
	v.erase(v.begin() + pos);
}
Money srednee(vec v)
{
	Money s(0,0);
	int n = v.size();
	for (int i = 0; i < v.size(); i++)
	{
		s = s + v[i];
	}
	return (s/n);
}
void summ_srednee(vec& v, Money el)
{
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = v[i] + el;
	}
}

int main2()
{
	srand(time(NULL));
	try
	{
		vector <Money> v;
		vector<Money>::iterator vi = v.begin();
		int n;
		cout << "N?" << endl;
		cin >> n;
		v = make_vector(n);
		print_vector(v);
		Money el = max(v);
		add_max(v, el);
		print_vector(v);
		int pos_min = min(v);
		del_min(v, pos_min);
		print_vector(v);
		el = srednee(v);
		summ_srednee(v, el);
		print_vector(v);
	}
	catch (Money)
	{
		cout << "Error!" << endl;
	}
	return 0;
}