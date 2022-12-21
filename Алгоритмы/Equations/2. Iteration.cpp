// f(x) = x - (1/(3 + sin(3.6 * x)))
// f'(x) = 1 + ((3.6 * cos(3.6 * x))/(3 + sin(3,6 * x))^2)
// [0;0,85]
#include <iostream>
#include <cmath>

int main()
{
	setlocale(LC_ALL, "Rus");
    float x, xPrev;
    double lambda = -0.05; // -1/20
    x = 0; // x0 из [0, 0,85] — выбранного заранее промежутка
    xPrev = -1; //делаем заведомо сильно меньше x, чтобы цикл правильно сработал
    double eps = 0.000001;

    while (abs(x - xPrev) > eps)
    {
        xPrev = x;
        x = lambda * (xPrev - (1 / (3 + sin(3.6 * xPrev)))) + xPrev;
    }
    std :: cout << "Корень по методу итераций: " << x << std :: endl;
    return 0;
}
