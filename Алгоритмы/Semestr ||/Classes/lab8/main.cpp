#include <iostream>
#include "Dialog.h"
#include "Windows.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");
  cout << "+ - Добавить элемент" << "\n";
  cout << "- - Удалить элемент" << "\n";
  cout << "m - Создать группу(m2 - из 2 элементов)" << "\n";
  cout << "s - Просмотр группы" << "\n";
  cout << "? - Вывести определенный элемент(?1 - номер 1)" << "\n";
  cout << "q - конец" << endl;
	Dialog D;
	D.Execute();
	return 0;
}
