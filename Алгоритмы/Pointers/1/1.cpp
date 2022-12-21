#include <iostream>

int main()
{
	setlocale(LC_ALL, "RUS");
	
	int n1, n2, tmp;
	int* ptr1;
	int* ptr2;


	std::cout << "Введите значение первой переменной" << std::endl;
	std::cin >> n1;

	ptr1 = &n1;
	tmp = *ptr1;

	std::cout << "Введите значение второй переменной" << std::endl;
	std::cin >> n2;
	
	ptr2 = &n2;
	*ptr1 = *ptr2;
	*ptr2 = tmp;

	std::cout << "Значение первой переменной= " << *ptr1 << std::endl;
	std::cout << "Значение второй переменной= " << *ptr2 << std::endl;
}
