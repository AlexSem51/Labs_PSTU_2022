#include <iostream>
using namespace std;

int main()
{
	int tmp;
	int SIZE = 6;
	int arr[] = { 2,6,7,1,-5,90 };

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
		{
			tmp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = tmp;
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}