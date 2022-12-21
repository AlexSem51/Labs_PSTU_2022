// f(x) = x - (1/(3 + sin(3.6 * x)))
// [0;0,85]
#include <iostream>
#include <cmath>

int main()
{
	setlocale(LC_ALL, "Rus");
	float a, b, c;
	float fA, fB, fC;
	double eps = 0.000000001;
	a = 0;
	b = 0, 85;
	while (b - a > eps)
	{
		c = (a + b) / 2;
		fA = a - (1 / (3 + sin(3.6 * a)));
		fB = b - (1 / (3 + sin(3.6 * b)));
		fC = c - (1 / (3 + sin(3.6 * c)));
		if (fA * fC < 0)
		{
			b = c;
		}
		else if (fC * fB < 0)
		{
			a = c;
		}
		else { std:: cout << "Что-то не то!" << std :: endl; }
	}
	std :: cout << "Корни: " << a << "; " << b << std :: endl;
	return 0;
}
