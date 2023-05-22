#include <iostream>
#include "Set.h"

int main()
{
    setlocale(LC_ALL, "rus");
    Set a(2), b(3);
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cin >> a >> b;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    a[1] = 100;
    std::cout << "a = " << a << std::endl;
    b = a;
    std::cout << "b = " << b << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "the lenght of a = " << a() << std::endl;
    std::cout << *(a.first()) << std::endl;
    Iterator i = a.first();
    ++i;
    std::cout << *i << std::endl;
    for (i = a.first(); i!=a.last(); ++i)
    {
        std::cout << *i << ' ';
    }
	return 0;
}
