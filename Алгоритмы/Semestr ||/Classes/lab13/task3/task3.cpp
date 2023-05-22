#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include "Money.h"
using namespace std;

typedef multiset<Money> multiSet;
typedef multiSet::iterator it;
Money s;
Money p;

multiSet make_multiSet(int n)
{
	multiSet ms;
	Money m;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		ms.insert(m);
	}
	return ms;
}
void print_multiSet(multiSet& ms)
{
	it i = ms.begin();
	while (i != ms.end())
	{
		cout << (*i) << ' ';
		i++;
	}
	cout << endl;
}
void add_max(multiSet& ms)
{
	Money max = *max_element(ms.begin(), ms.end());
	ms.insert(ms.begin(), max);
}
void del_min(multiSet& ms)
{
	it i = min_element(ms.begin(), ms.end());
	ms.erase(i);
}
Money srednee(multiSet& ms)
{
	it i = ms.begin();
	int n = ms.size();
	while (i != ms.end())
	{
		s = s + (*i);
		i++;
	}
	return (s / n);
}
void add_elem(multiSet& ms, Money& el)
{
	multiSet tmp;
	it i = ms.begin();
	while (i != ms.end())
	{
		Money t = (*i);
		tmp.insert(t + el);
		i++;
	}
	ms = tmp;
}

int main3()
{
	int n;
	cout << "N?" << endl;
	cin >> n;
	multiSet ms;
	ms = make_multiSet(n);
	print_multiSet(ms);
	add_max(ms);
	print_multiSet(ms);
	del_min(ms);
	print_multiSet(ms);
	p = srednee(ms);
	add_elem(ms, p);
	print_multiSet(ms);
	return 0;
}
