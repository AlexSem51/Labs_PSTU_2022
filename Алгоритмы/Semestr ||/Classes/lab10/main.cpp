#include <iostream>
#include <fstream>
#include "Money.h"
#include "file_work.h"
using namespace std;

int main() 
{
    int k, c, n;
    Money m;
    do {
        cout << "1. Make file" << endl;
        cout << "2. Print file" << endl;
        cout << "3. Delete record from file" << endl;
        cout << "4. Add record to file" << endl;
        cout << "5. Change record in file" << endl;
        cout << "0. Exit" << endl;
        cin >> c;
        char filename[30];
        switch (c) 
        {
        case 1:
            cout << "File name?" << endl;
            cin >> filename;
            k = make_file(filename);
            if (k < 0) cout << "Can't read file" << endl;
            break;
        case 2:
            cout << "File name?" << endl;
            cin >> filename;
            k = print_file(filename);
            if (k == 0) cout << "Empty file" << endl;
            if (k < 0) cout << "Can't read file" << endl;
            break;
        case 3:
            cout << "File name?" << endl;
            cin >> filename;
            cout << "N?" << endl;
            cin >> n;
            k = del_file(filename, n);
            if (k < 0) cout << "Can't read file" << endl;
            break;
        case 4:
            cout << "File name?" << endl;
            cin >> filename;
            cout << "N?" << endl;
            cin >> n;
            cout << "New money" << endl;
            cin >> m;
            k = add_file(filename, n, m);
            if (k < 0) cout << "Can't read file" << endl;
            if (k == 0) k = add_end(filename, m);
            break;
        case 5:
            cout << "File name?" << endl;
            cin >> filename;
            cout << "N?" << endl;
            cin >> n;
            cout << "New money" << endl;
            cin >> m;
            k = change_file(filename, n, m);
            if (k < 0) cout << "Can't read file" << endl;
            if (k == 0) cout << "Not such record" << endl;
            break;
        }
    } while (c != 0);

    return 0;
}
