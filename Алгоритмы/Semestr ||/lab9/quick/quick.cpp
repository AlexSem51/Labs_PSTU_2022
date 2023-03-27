#include <iostream>
using namespace std;

void quickSort(int* arr, int first, int last)
{
	if (first < last)
	{
		int left = first;
		int right = last;
		int mid = arr[(left + right) / 2];
		while (left < right)
		{
			while (arr[left] < mid)
			{
				left++;
			}
			while (arr[right] > mid)
			{
				right--;
			}
			if (left <= right)
			{
				int tmp = arr[left];
				arr[left] = arr[right];
				arr[right] = tmp;
				left++;
				right--;
			}
		}
		quickSort(arr, first, right);
		quickSort(arr, left, last);
	}
	return;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	int size;
	cout << "Ââåäèòå äëèíó ìàññèâà" << endl;
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = rand() % 101;
		cout << arr[i] << " ";
	}
	cout << endl;
	quickSort(arr, 0, size - 1);
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	delete[] arr;
	return 0;
}