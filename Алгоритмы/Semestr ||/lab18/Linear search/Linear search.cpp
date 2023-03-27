#include <iostream>
#include <ctime>
using namespace std;

int linearSearch(int arr[], int key, int size)
{
	for (int i = 0; i < size; i++) 
	{
		if (arr[i] == key) 
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	int size, key;
	cout << "Ââåäèòå ðàçìåð ìàññèâà: "; 
	cin >> size;
	int* arr = new int[size];
	cout << "Ìàññèâ: ";
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 101;
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Ââåäèòå ýëåìåíò, êîòîðûé íàäî íàéòè: ";
	cin >> key;
	cout << endl;
	if (linearSearch(arr, key, size) == -1)
	{
		cout << "Ýëåìåíò íå íàéäåí" << endl;
	}
	else
	{
		cout << "Ýëåìåíò íàéäåí ïîä íîìåðîì: " << linearSearch(arr, key, size) + 1 << endl;
	}

	delete[] arr;
	return 0;
}