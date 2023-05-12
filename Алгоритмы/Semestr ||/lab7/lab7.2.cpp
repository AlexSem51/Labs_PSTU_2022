#include <iostream>
#include <stdarg.h>
using namespace std;

int sum(int k, ...)
{
	va_list factor;
	va_start(factor, k);
	int s = 0;
	
	for (int i=0 ; i < k; i++)

		{
		    int tmp = va_arg(factor, int);
			s += tmp ;
		}
		
	va_end(factor);
	return s;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << sum(3, 1, 2, 3,4,5) << endl;
	cout << sum(10, 2, 4, 6, 8, 10, 12, 14, 16, 17, 18) << endl;
	cout << sum(12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) << endl;
	return 0;
}
