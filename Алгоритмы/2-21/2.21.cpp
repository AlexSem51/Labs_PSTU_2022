#include <iostream>

using namespace std;

int num1, num2;

int main()
{
    setlocale(LC_ALL, "RUS");

    bool flag1 = false;// отвечает за окончание последовательности(т.е вводится 0)
    bool flag2 = true;// отвечает за упорядоченность чисел по возрастанию
    bool flag_first = false;

    cout << "Введите первое число" << endl;
    cin >> num1;

    if (num1 == 0)
        flag_first = true;

    while (!flag1 && !flag_first)
    {
        cout << "Введите следующее число" << endl;
        cin >> num2;
        if (num2 == 0)
        {
            flag1 = true;
        }
        if (num2 < num1 && num2 != 0)
        {
            flag2 = false;
        }
        num1 = num2;
    }
    if (flag_first)
    {
        cout << "Последовательности нет(первым числом ввели 0)" << endl;
    }
    if (flag2)
    {
        cout << "Числа упорядочены по возрастанию";
    }
    else
    {
        cout << "Числа упорядочены не по возрастанию";
    }

    return 0;
}