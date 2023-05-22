#include <iostream>
#include <vector>
#include "Money.h"
#include "Set.h"
using namespace std;

int main3()
{
	Set<Money> vec(5);
	vec.Print();
	Money m = vec.max();
	vec.add_max(m);
	vec.Print();
	int pos_min = vec.min();
	vec.del_min(pos_min);
	vec.Print();
	m = vec.srednee();
	vec.summ_srednee(m);
	vec.Print();
	return 0;
}