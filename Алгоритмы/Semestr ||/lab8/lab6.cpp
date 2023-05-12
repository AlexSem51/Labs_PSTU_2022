#include <cstring>
#include <iostream>
using namespace std;

void Gets(char* str){
    cin.getline(str,255);
}

bool IsLetter(char ch){
    return ch>='A' && ch<='Z' || ch>='a' && ch<='z';
}

bool IsDigit(char ch){
    return ch>='0' && ch<='9';
}

char* Letters_then_digits(char* string1){
    unsigned long long size_of_str = strlen(string1);
    char* new_string = new char[size_of_str];
    int counter = 0;
    for(int i=0;i<size_of_str;i++){
        if(IsLetter(string1[i])){
            new_string[counter]= string1[i];
            counter++;
        }
    }
    for(int i=0;i< size_of_str;i++){
        if(IsDigit(string1[i])){
            new_string[counter]=string1[i];
            counter++;
        }
    }
    for(int i=0;i<size_of_str;i++){
        if(!IsDigit(string1[i]) && !IsLetter(string1[i])){
            new_string[counter]=string1[i];
            counter++;
        }
    }
    return new_string;
}

int main( )
{
    char* str=new char[255];
    Gets(str);
    str = Letters_then_digits(str);
    for(int i=0;i<strlen(str);i++){
        cout<<str[i];
    }
    cout<<endl;
    return 0;
}
