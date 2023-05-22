#pragma once
#include <iostream>
#include <fstream>
#include "Money.h"
using namespace std;

int make_file(const char* f_name) 
{
    fstream stream(f_name, ios::out | ios::trunc);
    if (!stream) return -1;
    int n;
    Money m;
    cout << "N?" << endl;
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cin >> m;
        stream << m << endl;
    }
    stream.close();
    return n;
}

int print_file(const char* f_name) 
{
    fstream stream(f_name, ios::in);
    if (!stream) return -1;
    int i = 0;
    Money m;
    while (stream >> m) 
    {
        cout << m << endl;
        i++;
    }
    stream.close();
    return i;
}

int del_file(const char* f_name, int k) 
{
    fstream temp("temp", ios::out);
    fstream stream(f_name, ios::in);
    if (!stream) return -1;
    Money m; int i = 0;
    while (stream >> m) 
    {
        if (stream.eof()) break;
        i++;
        if (i != k) temp << m;
    }
    stream.close();
    temp.close();
    remove(f_name);
    rename("temp", f_name);
    return i;
}

int add_file(const char* f_name, int k, Money mm) 
{
    fstream temp("temp", ios::out);
    fstream stream(f_name, ios::in);
    if (!stream) return -1;
    Money m; int i = 0; int l = 0;
    while (stream >> m) 
    {
        if (stream.eof()) break;
        i++;
        if (i == k) 
        {
            temp << mm;
            l++;
        }
        temp << m;
    }
    stream.close();
    temp.close();
    remove(f_name);
    rename("temp", f_name);
    return l;
}

int add_end(const char* f_name, Money mm) 
{
    fstream stream(f_name, ios::app);
    if (!stream) return -1;
    stream << mm;
    return 1;
}

int change_file(const char* f_name, int k, Money mm) 
{
    fstream temp("temp", ios::out);
    fstream stream(f_name, ios::in);
    if (!stream) return -1;
    Money m; int i = 0; int l = 0;
    char x;
    while (stream >> m) 
    {
        if (stream.eof()) break;
        i++;
        if (i == k) 
        {
            cout << m << " - is changing. Continue [y/n]?" << endl;
            cin >> x;
            if (x == 'n' || x == 'N') break;
            temp << mm;
            l++;
        }
        else temp << m;
    }
    stream.close();
    temp.close();
    remove(f_name);
    rename("temp", f_name);
    return l;
}
int del_file_equal(const char* f_name, Money mm)
{
    fstream temp("temp", ios::out);
    fstream stream(f_name, ios::in);
    if (!stream) return -1;
    Money m; int i = 0;
    while (stream >> m)
    {
        if (stream.eof()) break;
        i++;
        if (m != mm) temp << m;
    }
    stream.close();
    temp.close();
    remove(f_name);
    rename("temp", f_name);
    return i;
}
int change_file_1rub50kop(const char* f_name)
{
    fstream temp("temp", ios::out);
    fstream stream(f_name, ios::in);
    if (!stream) return -1;
    Money m;
    Money mm(1, 50);
    while (stream >> m)
    {
        Money s(0, 0);
        if (stream.eof()) break;
        s = m + mm;
        temp << s;
    }
    stream.close();
    temp.close();
    remove(f_name);
    rename("temp", f_name);
    return 1;
}
int add_file_N_elem(const char* f_name, int k,int N)
{
    fstream temp("temp", ios::out);
    fstream stream(f_name, ios::in);
    if (!stream) return -1;
    Money m; int i = 0;
    while (stream >> m)
    {
        if (stream.eof()) break;
        i++;
        if (i == k)
        {
            Money m_new;
            for (int j = 0; j < N; j++)
            {
                cin >> m_new;
                temp << m_new;
            }
        }
        temp << m;
    }
    stream.close();
    temp.close();
    remove(f_name);
    rename("temp", f_name);
    return N;
}
