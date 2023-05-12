#include <iostream>
#include <fstream>
using namespace std;

void rewrite_string(int N,int K){
    ifstream file_in("F1.txt", ios::app);
    ofstream file_out("F2.txt",ios::app);
    string buffer;
    int i=0;
    for(;i<N;i++){
        getline(file_in,buffer,'\n');
    }
    for(;i<K;i++){
        getline(file_in,buffer,'\n');
        file_out << buffer<<endl;
    }
    file_in.close();
    file_out.close();
}

int find_letters(){
    ifstream file_in("F2.txt",ios::app);
    string buffer;
    int N=0;
    while(!file_in.eof()){
        getline(file_in,buffer,'\n');
        for(char j : buffer){
            //find vowels for latin alphabet
            bool Latin_lower = (j=='a' || j=='e' || j=='i' || j=='o' || j=='u');
            bool Latin_upper = (j=='A' || j=='E' || j=='I' || j=='O' || j=='U');
            if(!(Latin_lower || Latin_upper)){
                N++;
            }
        }
    }
    return N;
}

int main(){
    rewrite_string(5,8);
    cout<<"Number of consonants in F2 is "<<find_letters();
    return 0;
};
