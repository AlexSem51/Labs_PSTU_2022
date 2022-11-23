/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;
int main() 
{
    int n; 
    int max=0 ;
    int num;

    cout<< "Введите колво чисел" << endl;

    cin>>n;

    for (int i = 1;i<=n;i++)
    {
        cin >> num;
    
        if (num>max)
        {
            max=num;
        
        }
    }    
    cout<<max<<endl;
    return 0;
    
}
