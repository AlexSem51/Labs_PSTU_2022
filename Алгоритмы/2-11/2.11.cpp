/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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
    int max ;
    int num;
    int min;
    int sum;
    cout<< "Введите колво чисел" << endl;

    cin>>n;

    for (int i = 1;i<=n;i++)
    {
        cin >> num;
    
        if (num>max)
        {
            max=num;
            
        }
        
        
        if (num<min)
        {
            min=num;
            
        }
        
        
        
    }    
    sum=min+max;
    cout<<"Сумма:"<<sum;
    
    return 0;
    
}
