#include <iostream>
using namespace std;

void countSort(int arr[], int size)
{
    int* output = new int[size];
    int* count;
    int max = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max) 
        { 
            max = arr[i]; 
        }
    }

    count = new int[max + 1];
    for (int i = 0; i <= max; ++i)
    {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i]; 
    }
    delete[] count;
    delete[] output;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    int size;
    cout << "Ââåäèòå äëèíó ìàññèâà" << endl;
    cin >> size;
    int* arr = new int[size];

    for (int i = 0; i < size; i++) 
    {
        arr[i] = rand() % 101;
    }
    cout << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    countSort(arr, size);

    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}