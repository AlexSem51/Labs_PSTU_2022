#include <iostream>
#include <complex>
using namespace std;

double substraction(double a,double b){
    //returns difference of real numbers
    return a-b;
}

complex<double> substraction(complex<double> a, complex<double> b){
    //returns complex number equal to difference a-b (Ra-Rb,Ia-Ib)
    return a-b;
}

int main(){
    cout<<"Введите два действительных числа"<<endl;
    double a,b;
    cin>>a>>b;
    complex<double>c,d;
    cout<<"Введите два комплексных числа в формате (Ra,Ia) (Rb,Ib) без пробелов в скобках"<<endl;
    cin>>c>>d;
    cout<<"Разность действительных чисел равна "<<substraction(a,b)<<endl;
    cout<<"Разность комплексных чисел равна "<<substraction(c,d)<<endl;
    return 0;
}
