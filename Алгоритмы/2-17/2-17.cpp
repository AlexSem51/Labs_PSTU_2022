#include <iostream>
#include <cmath>
using namespace std;
int n,f;
float x, sum;
int main()
{
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		if (i < 1) { f = 1;}
		else { f *= i; }
		sum += pow(x, i) / f;
	}
	cout << endl;
	cout << sum;
	return 0;
}