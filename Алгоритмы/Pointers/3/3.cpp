//Сложение двух чисел с плавающей запяток через указатели
#include <iostream>

int main()
{
	setlocale(LC_ALL, "RUS");
	float a, b, sum = 0;
	float* ptr1;
	float* ptr2;

	std::cout << "Введите первое число " << std::endl;
	std::cin >> a;

	std::cout << "Введите второе число " << std::endl;
	std::cin >> b;

	ptr1 = &a;
	ptr2 = &b;

	sum = *ptr1 + *ptr2;

	std::cout << "Их сумма равна " << sum << std::endl;
}
