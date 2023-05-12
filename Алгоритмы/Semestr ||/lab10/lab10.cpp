#include <iostream>
#include <ctime>
#include "random"
#define base_size 7

using namespace std;

struct Matrix{
    int** data;
    int rows;
    int cols;
};

void fill_matrix(int n,int min,int max,Matrix &matrix){
    int i,j;
    matrix.data=new int*[n];
    matrix.rows=n;
    matrix.cols=n;
    for (i=0;i<n;i++)
    {
        matrix.data[i]=new int[n];
        for (j=0;j<n;j++)
            matrix.data[i][j]=min + rand()%(max-min+1);;
    }
}

void delete_string(Matrix &matrix,int n,int k){
    Matrix new_matrix{};
    new_matrix.data = new int*[n-1];
    new_matrix.rows--;
    new_matrix.cols=matrix.cols;
    for(int i=0;i<n-1;i++){
        if(i<k-1) new_matrix.data[i]=matrix.data[i];
        else new_matrix.data[i]=matrix.data[i+1];
    }
    free(matrix.data);
    matrix = new_matrix;
}

void print_matrix(Matrix &matrix,int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<matrix.data[i][j]<<' ';
        }
        cout<<endl;
    }
}

int main(){
    srand(time(nullptr));
    Matrix test_matrix{};
    int j=1;
    fill_matrix(base_size,-1000,1000,test_matrix);
    cout<<"Сгенерированный массив"<<endl;
    print_matrix(test_matrix,test_matrix.rows,test_matrix.cols);
    cout<<endl;
    cout<<endl;
    cout<<"Какую строку удаляем?"<<endl;
    cin>>j;
    delete_string(test_matrix,base_size,j);
    cout<<"Массив без "<<j<<" строки"<<endl;
    print_matrix(test_matrix,test_matrix.rows,test_matrix.cols);
    for(int i = 0;i<6;i++){
        delete []test_matrix.data[i];
    }
    delete []test_matrix.data;
    return 0;
}
