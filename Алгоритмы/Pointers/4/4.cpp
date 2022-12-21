#include<iostream>
//Найти минимальное и максимальное число в последовательности через указтетели
int main()
{
	setlocale(LC_ALL, "RUS");
	int n;
	int tmp;
	int* ptr = &tmp;
	int max;
	int min;

	std::cout << "Введите длину последовательности:" << std::endl;
	std::cin >> n;
	std::cout << "Введите первое число:" << std::endl;
	std::cin >> tmp;

	max = *ptr;
	min = *ptr;

	for (int i = 2; i <= n; i++)
	{
		std::cin >> *ptr;

		if (*ptr > max)
		{
			max = *ptr;
		}
		else if (*ptr < min)
		{
			min = *ptr;
		}
	}

	std::cout << "Максимальный элемент= " << max << std::endl;
	std::cout << "Минимальный элемент= " << min << std::endl;
}
