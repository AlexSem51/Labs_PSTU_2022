#include <iostream>
using namespace std;

int main()
{
	int tmp;
	int SIZE = 6;
	int arr[] = { 2,6,7,1,-5,90 };
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < SIZE-i-1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}
