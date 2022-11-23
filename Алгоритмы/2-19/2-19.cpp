
#include <iostream>
using namespace std;

int n,s;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0) s -= i;
        else s += i;
    }
    cout << s;
    return 0;
}