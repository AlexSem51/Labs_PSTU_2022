#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from, char to, char tmp)
{
    if (n == 0) 
    {
        return;
    }
    towerOfHanoi(n - 1, from, tmp, to);
    cout << "Move ring " << n << " from " << from << " to " << to << endl;
    towerOfHanoi(n - 1, tmp, to, from);
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int n;

    cout << "Enter number of rings: ";
    cin >> n;
    cout << endl;

    towerOfHanoi(n, '1', '3', '2');
    return 0;
}