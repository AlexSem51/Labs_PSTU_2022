#include <iostream>
#include "Student.h"

using namespace std;

int main() {
    string name, group;
    float gpa;
    cout << "Введите данные студента" << endl;
    cin >> name;
    cin >> group;
    cin >> gpa;
    Student stud0;
    Student stud1(name, group, gpa);
    Student stud2(stud1);
    cout << stud0.get_name() << " " << stud0.get_group() << stud0.get_GPA() << endl;
    cout << stud1.get_name() << " " << stud1.get_group() << stud1.get_GPA() << endl;
    cout << stud2.get_name() << " " << stud2.get_group() << stud2.get_GPA() << endl;
    stud0.set_Name("Ivan");
    stud0.set_GPA(4.5);
    stud0.set_Group("K101");
    cout << stud0.get_name() << " " << stud0.get_group() << stud0.get_GPA() << endl;
    return 0;
}
