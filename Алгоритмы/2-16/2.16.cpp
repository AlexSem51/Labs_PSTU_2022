#include <iostream>



int main()
{
    int N; int sum = 0;

    std::cin >> N;

    for (int i = 1; i <= N; i++)
    {
        if (i % 2 == 1)
        {
            sum -= i;
        }
        else
        {
            sum += i;
        }
    }

    std::cout << sum;
}