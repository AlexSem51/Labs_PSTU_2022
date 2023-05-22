#include <iostream>
#include <vector>
#include <stack>
#include "Set.h"
#include "Money.h"
using namespace std;

int main5()
{
	Set<Money> vec(3);
	vec.Print();
	Money el = vec.max();
	vec.add_max_to_stack(el,0);
	vec.Print();
	vec.del_min_from_stack();
	vec.Print();
	el = vec.srednee();
	vec.summ_srednee(el);
	vec.Print();
	return 0;
}