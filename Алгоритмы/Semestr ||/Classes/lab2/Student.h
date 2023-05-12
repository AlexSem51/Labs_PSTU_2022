
#ifndef MAIN_CPP_STUDENT_H
#define MAIN_CPP_STUDENT_H

#include <iostream>

class Student {
    std::string Name;
    std::string Group;
    float GPA;
public:
    Student();

    Student(std::string name, std::string group, float gpa);

    Student(Student &dude);

    ~Student();

    std::string get_name() { return Name; }

    std::string get_group() { return Group; }

    float get_GPA() { return GPA; }

    void set_Name(std::string name) { Name = name; }

    void set_Group(std::string group) { Group = group; }

    void set_GPA(float gpa) { GPA = gpa; }

    void show() {
        std::cout << "This student has name " << Name << ", he/she is in group " << Group << ", and he/she has GPA "
                  << GPA << std::endl;
    }
};

#endif //MAIN_CPP_STUDENT_H
