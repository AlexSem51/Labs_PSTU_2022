#include <iostream>

using namespace std;

int main()
{
int n;
int tmp, sum = 0;

cin >> n;

for (int i = 1; i <= n; i++)
{
    tmp = 1;
    for (int j = i; j <= 2*i; j++)
    {
        tmp *= j;
    }
    sum += tmp;
}
cout << sum << endl;
}
