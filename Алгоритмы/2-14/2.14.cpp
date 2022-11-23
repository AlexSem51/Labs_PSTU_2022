#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    int N;
    int sum = 0;

    cout << "Введите N = ";
    cin >> N;

    while (N != 0)
    {
        sum += N % 10;
        N /= 10;
    }
    cout << "sum = " << sum << endl;

    return 0;
}