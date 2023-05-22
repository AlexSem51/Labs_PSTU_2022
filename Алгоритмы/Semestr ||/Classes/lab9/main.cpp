#include <iostream>
#include "Set.h"
#include "Error.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Ìàêñèìàëüíûé ðàçìåð ìíîæåñòâà ðàâåí 5" << endl;
	try
	{
		Set a(2);
		a[0] = 1;
		a[1] = 2;
		cout << "Ìíîæåñòâî a = ";
		cout << a << endl;
		int idx;
		cout << "Ââåäèòå ðàçìåð ìíîæåñòâà b:";
		cin >> idx;
		Set b(idx);
		cin >> b;
		cout << "Ðàçìåð ìíîæåñòâà a: " << a() << endl;
		cout << "Ðàçìåð ìíîæåñòâà b: " << b() << endl;
		cout << "Ìíîæåñòâî b = ";
		cout << b << endl;
		cout << "b++: ";
		cout << b++ << endl;
		cout << "a + b = " << a + b << endl;
		
	}
	catch (Error& e)
	{
		e.what();
	}
	return 0;
}
