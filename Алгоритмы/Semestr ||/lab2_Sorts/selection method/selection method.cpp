#include <iostream>
using namespace std;

int main()
{
	int tmp;
	int SIZE = 6;
	int arr[] = { 2,6,7,1,-5,90 };
	for (int i = 0; i < SIZE-1; i++)
	{
		int min = i;
		for (int j = i; j < SIZE; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
	}
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}
