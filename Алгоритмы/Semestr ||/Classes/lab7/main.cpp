#include <iostream>
#include "Money.h"
#include "Set.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	Set<int> A(2, 0);	
	cout << "A = " << A << endl;
	cin >> A;
	cout << "A = " << A << endl;
	Set<int> B(3, 1);
	std::cout << "B = " << B << endl;
	B = A;
	cout << "B = " << B << endl;
	cout << A[1] << endl;
	cout << "the length of A = " << A() << endl;
	cout << "A + B = " << A + B << endl;
	Money t;
	cin >> t;
	cout << t << endl;
	Money k;
	cin >> k;
	cout << k << endl;
	Money p;
	p = t + k;
	cout << p << endl;
	Set<Money> C(2, t);
	cout << "C = " << C << endl;
	cin >> C;
	cout << "C = " << C << endl;
	Set<Money> D(3, t);
	cout << "D = " << D << endl;
	D = C;
	cout << "D = " << D << endl;
	cout << C[1] << endl;
	cout << "the length of C = " << C() << endl;
	cout << "C + D = " << C + D << endl;
	return 0;
}
