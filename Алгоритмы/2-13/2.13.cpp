#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    int a, b, c, x1, x2, d, x;

    cout << "enter the values of a, b, c: " << endl;
    cin >> a >> b >> c;

    d = b * b - 4 * a * c;
    if (d > 0)
    {
        x1 = ((-b) + sqrt(d) / (2 * a));
        x2 = ((-b) - sqrt(d) / (2 * a));
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }

    if (d == 0)
    {
        x = -(b / (2 * a));
        cout << "x = " << x << endl;
    }
    if (d < 0)
    {
        cout << "D < 0, КОРНЕЙ НЕТ" << endl;
    }
}