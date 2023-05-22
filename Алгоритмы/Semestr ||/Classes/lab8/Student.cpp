#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

Student::Student(void) : Person()
{
	Rating = 0;
}
Student::~Student(void)
{
}
void Student::Show(void)
{
	cout << "Èìÿ: " << Name << endl;
	cout << "Âîçðàñò: " << Age << endl;
	cout << "Ðåéòèíã: " << Rating << endl;
}
void Student::Input(void)
{
	cout << "Èìÿ: ";
	cin >> Name;
	cout << "Âîçðàñò: ";
	cin >> Age;
	cout << "Ðåéòèíã: ";
	cin >> Rating;
	cout << endl;
}
Student::Student(string name, int age, float rating) : Person(name, age)
{
	Rating = rating;
}
Student::Student(const Student& s)
{
	Name = s.Name;
	Age = s.Age;
	Rating = s.Rating;
}
void Student::setRating(float rating)
{
	Rating = rating;
}
float Student::getRating(void)
{
	return Rating;
}
Student& Student::operator=(const Student& s)
{
	if (this == &s)
	{
		return *this;
	}
	Name = s.Name;
	Age = s.Age;
	Rating = s.Rating;
	return *this;
}
