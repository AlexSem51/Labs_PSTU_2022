// f(x) = x - (1/(3 + sin(3.6 * x)))
// f'(x) = 1 + ((3.6 * cos(3.6 * x))/(3 + sin(3,6 * x))^2)
// [0;0,85]
#include <iostream>
#include <cmath>

int main()
{
    setlocale(LC_ALL, "Rus");
    float x, xPrev;
    x = 0;
    xPrev = 0;
    double eps = 0.000001;

    while (abs(x - xPrev) > eps)
    {
        xPrev = x;
        x = xPrev - ((xPrev - (1 / (3 + sin(3.6 * xPrev)))) / (1 + ((3.6 * cos(3.6 * xPrev)) / pow((3 + sin(3.6 * xPrev)), 2))));
    }
    std :: cout << "Корень: " << x << std :: endl;
    return 0;
}
