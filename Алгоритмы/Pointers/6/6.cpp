//Подсчитать количество гласных и согласных в строке через указатели (в строке только буквы русского алфавита)
#include<iostream>
#include<string>

int main()
{
    setlocale(LC_ALL, "RUS");
    int countC, countV;
    countC = countV = 0;

    std::string s;
    std::cout << "Введите строку:" << std::endl;
    std::cin >> s;

    const char* sptr = s.c_str();
    for (int i = 0; i < s.length(); i++)
    {
        switch (*sptr)
        {
        case 'А':
        case 'Е':
        case 'И':
        case 'О':
        case 'У':
        case 'Э':
        case 'Ю':
        case 'Я':
        case 'а':
        case 'е':
        case 'и':
        case 'о':
        case 'у':
        case 'ы':
        case 'э':
        case 'ю':
        case 'я':
        case 'Ы':
            countV++;
            break;
        default:
            countC++;
            break;
        }

        *sptr++;

    }

    std::cout << "Количество гласных = " << countV << std::endl;
    std::cout << "Количество согласных = " << countC << std::endl;
    return 0;
}
