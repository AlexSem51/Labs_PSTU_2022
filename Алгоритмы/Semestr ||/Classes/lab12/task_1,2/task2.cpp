#include <iostream>
#include <map>
#include "Money.h"
using namespace std;

typedef multimap<int, Money> multiMap;
typedef multiMap::iterator it;

multiMap make_multiMap(int n)
{
	multiMap mm;
	Money a;
	for (int i = 1; i <= n; i++)
	{
		cout << "Input: ";
		cin >> a;
		mm.insert(make_pair(i, a));
	}
	return mm;
}
void print_multiMap(multiMap mm)
{
	for (auto& e : mm)
	{
		cout << e.first << " : " << e.second << endl;
	}
	cout << endl;
}
Money max(multiMap mm)
{
	it i = mm.begin();
	Money m = (*i).second;
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
int min(multiMap mm)
{
	it i = mm.begin();
	int num = 0;
	int k = 0;
	Money m = (*i).second;
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
Money srednee(multiMap mm)
{
	Money s(0, 0);
	int n = 0;
	for (auto& e : mm)
	{
		s = s + e.second;
	}
	n = mm.size();
	return (s / n);
}
void summ_srednee(multiMap& mm, Money el)
{
	for (auto& e : mm)
	{
		e.second = e.second + el;
	}
}

int main2()
{
	int n;
	cout << "N?" << endl;
	cin >> n;
	multiMap mm = make_multiMap(n);
	print_multiMap(mm);
	Money m = max(mm);
	mm.insert(make_pair(0, m));
	print_multiMap(mm);
	int pos = min(mm);
	mm.erase(pos);
	print_multiMap(mm);
	Money el = srednee(mm);
	summ_srednee(mm, el);
	print_multiMap(mm);
	return 0;
}
