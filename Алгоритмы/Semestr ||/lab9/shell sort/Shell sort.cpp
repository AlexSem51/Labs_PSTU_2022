#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	int n, d, j, tmp;
	cout << "Ââåäèòå ðàçìåð ìàññèâà" << endl;
	cin >> n;
	int* a = new int[n];
	cout << "Íåîòñîðòèðîâàííûé ìàññèâ:";
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 101;
		cout << a[i] << ' ';
	}
	cout << endl;
	d = n / 2;
	while (d > 0)
	{
		for (int i = 0; i < n - d; i++)
		{
			j = i;
			while (j >= 0 and a[j] > a[j + d])
			{
				tmp = a[j];
				a[j] = a[j + d];
				a[j + d] = tmp;
				j -= d;
			}
		}
		d = d / 2;
	}
	cout << "Îòñîðòèðîâàííûé ìàññèâ:";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	delete[] a;
	return 0;
}