#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	float max, a, n;
	cin >> n;
	max = sin(n + 1 / n);
	for (int i = 1; i <= n; i++)
	{
		if (n > 0)
		{
			a = sin(n + i / n);
			cout << a << " ";
			if (a > max)
				max = a;
		}
	}
	cout << endl;
	cout << max;
	return 0;
}