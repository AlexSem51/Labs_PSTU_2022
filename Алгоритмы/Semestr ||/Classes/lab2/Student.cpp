#include "Student.h"

Student::Student() {
    Name = "";
    Group = "";
    GPA = 0;
};

Student::Student(std::string name, std::string group, float gpa) {
    Name = name;
    Group = group;
    GPA = gpa;
}

Student::Student(Student &dude) {
    Name = dude.Name;
    Group = dude.Group;
    GPA = dude.GPA;
}

Student::~Student() {
    std::cout << "Deleting student " << Name << std::endl;
    Name = "";
    Group = "";
    GPA = 0;
}
