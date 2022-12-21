#include <iostream>

int main()
{
	setlocale(LC_ALL, "RUS");
	int a, b, sum = 0;
	int* ptr1;
	int* ptr2;

	std::cout << "Введите первое число " << std::endl;
	std::cin >> a;

	std::cout << "Введите второе число " << std::endl;
	std::cin >> b;

	ptr1 = &a;
	ptr2 = &b;

	sum = *ptr1 + *ptr2;

	std::cout << "Их сумма равна " << sum << std::endl;
}
