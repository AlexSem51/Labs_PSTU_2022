#include <iostream>
#include <map>
#include "Set.h"
#include "Money.h"
using namespace std;

int main3()
{
	int n;
	cout << "N?" << endl;
	cin >> n;
	Set<Money> mm(n);
	mm.Print();
	Money m = mm.max();
	mm.add_max(m);
	mm.Print();
	int pos = mm.min();
	mm.del_min(pos);
	mm.Print();
	Money el = mm.srednee();
	mm.summ_srednee(el);
	mm.Print();
	return 0;
}