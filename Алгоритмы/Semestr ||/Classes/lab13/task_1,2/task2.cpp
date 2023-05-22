#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include "Money.h"
using namespace std;

typedef stack<Money> st;
typedef vector<Money> vec;
Money s;
Money p;

st make_stack(int n)
{
	st stack;
	Money m;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		stack.push(m);
	}
	return stack;
}
st print_stack(st stack)
{
	while (!stack.empty())
	{
		cout << stack.top() << ' ';
		stack.pop();
	}
	cout << endl;
	return stack;
}
vec copy_stack_to_vector(st stack)
{
	vec v;
	while (!stack.empty())
	{
		v.push_back(stack.top());
		stack.pop();
	}
	return v;
}
st copy_vector_to_stack(vec v)
{
	st stack;
	for (int i = 0; i < v.size(); i++)
	{
		stack.push(v[i]);
	}
	return stack;
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
	Money a = v[0];
	int n = v.size();
	for (int i = 1; i < v.size(); i++)
	{
		a = a + v[i];
	}
	return (a / n);
}
void summ_srednee(Money& el)
{
	el = el + p;
}

int main2()
{
	int n;
	cout << "N?" << endl;
	cin >> n;
	st stack;
	stack = make_stack(n);
	print_stack(stack);
	vec v;
	v = copy_stack_to_vector(stack);
	vec::iterator i;
	i = max_element(v.begin(), v.end());
	cout << "max = " << (*i) << endl;
	Money max = (*i);
	v.insert(v.begin(), max);
	stack = copy_vector_to_stack(v);
	v = copy_stack_to_vector(stack);
	stack = copy_vector_to_stack(v);
	print_stack(stack);
	i = min_element(v.begin(), v.end());
	cout << "min = " << (*i) << endl;
	s = (*i);
	v.erase(remove_if(v.begin(), v.end(), Equal_s()), v.end());
	stack = copy_vector_to_stack(v);
	print_stack(stack);
	p = srednee(v);
	for_each(v.begin(), v.end(), summ_srednee);
	stack = copy_vector_to_stack(v);
	print_stack(stack);
	return 0;
}