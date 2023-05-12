#include <iostream>
#include <cstdlib>
#include <ctime>
#include "random"
using namespace std;
int mas[10][10];
void Find_Saddle(int mass[10][10]){
    int min_row[10];
    int max_row[10];
    int min_col[10];
    int max_col[10];
    for(int i=0;i<10;i++){
        max_col[i]=-1000000000;
        max_row[i]=-1000000000;
        min_col[i]=1000000000;
        min_row[i]=1000000000;
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(mass[i][j] < min_row[i]){
                min_row[i]=mass[i][j];
            }
            if(mass[i][j] < min_col[j]){
                min_col[j]=mass[i][j];
            }
            if(mass[i][j] > max_row[i]){
                max_row[i]=mass[i][j];
            }
            if(mass[i][j] > max_col[i]){
                max_col[j]=mass[i][j];
            }
        }
    }
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++){
            if(mass[i][j] == min_row[i] && mass[i][j] == max_col[j] || mass[i][j] == max_row[i] && mass[i][j] == min_col[j]){
                cout << "Saddle point is found on place " << i << " " << j << " and is equal to "<< mass[i][j] << endl;
            }
        }
    }
}

int main(){
    srand(time(NULL));
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            //mas[i][j]=rand()%1001;
            mas[i][j]=(i+1)*(j+1);
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<mas[i][j]<<" ";
        }
        cout<<endl;
    }
    Find_Saddle(mas);
    return 0;
}
