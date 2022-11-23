#include <iostream>
using namespace std;

int main()
{
	int n,z,new_n = 0;
	cin >> n;
	while (n > 0) 
	{
		z = n % 10;
		new_n = new_n * 10 + z;
		n = n / 10;
	}
	cout << new_n;
	return 0;
}