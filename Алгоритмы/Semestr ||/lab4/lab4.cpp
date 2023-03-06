#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
   int a[100];

   int n=10,  d=5, j;

   cout<<"Введите размер массива: " << endl;
   for (int i=0; i<n; i++)
   {
       a[i]=rand()%100;

       cout<<a[i]<<" ";
   }
    cout<<"\nИзмененный массив: " << endl;
   for (int i=0; i<n-d; i++)
   {
        cout<<a[i]<<" ";
   }
   //Сдвиг массива на три элемента
    for (int i = n-2; i >= 0; i--) {

        a[i + 3] = a[i];

    }
//Добавление новых элементов
    for (int i = 0; i < 3; i++) {

        a[i] = a[(i + 3) + 1] + 2;

    }
    cout<<"\nИзмененный массив2: "<<endl; //Изменяет массив из 5и элементов 
    for (int i = 0; i < n - 2; i++) {


        cout << a[i] << " ";


    }
}
