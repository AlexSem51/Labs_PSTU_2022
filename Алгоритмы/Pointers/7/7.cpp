//Изменение значение переменной через указатель
#include <iostream>

int main()
{
	setlocale(LC_ALL, "RUS");
	int n;
	int n_new;
	int* ptr = &n;

	std::cout << "Введите значение n" << std::endl;
	std::cin >> *ptr;

	std::cout << "Введите новое значение n" << std::endl;
	std::cin >> n_new;

	*ptr = n_new;

	std::cout << "Новое значение n = " << n << std::endl;

	return 0;
}
