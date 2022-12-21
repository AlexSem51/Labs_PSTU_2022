#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	float n, a, max;
	int k = 1;
	int i = 2;

	cout << "Ââåäèòå êîëè÷åñòâî ýëåìåíòîâ n" << endl;
	cin >> n;

	max = sin(n + 1 / n);

	while (i <= n)
	{
		a = sin(n + i / n);
		if (a > max)
		{
			max = a;
			k = 1;
		}
		else if (a == max)
		{
			k++;
		}
		i++;
	}

	cout << "Ìàêñèìàëüíûé ýëåìåíò ïîñëåäîâàòåëüíîñòè: " << max << endl;
	cout << "Êîëè÷åñòâî ýëåìåíòîâ, ñîâïàäàþùèõ ñ ìàêñèìàëüíûì:" << k << endl;

	return 0;
}
