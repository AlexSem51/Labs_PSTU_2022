#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

Person::Person(void)
{
	Name = "";
	Age = 0;
}
Person::~Person(void)
{
}
void Person::Show(void)
{
	cout << "Èìÿ: " << Name << endl;
	cout << "Âîçðàñò: " << Age << endl;
}
void Person::Input(void)
{
	cout << "Èìÿ: ";
	cin >> Name;
	cout << "Âîçðàñò: ";
	cin >> Age;
	cout << endl;
}
Person::Person(string name, int age)
{
	Name = name;
	Age = age;
}
Person::Person(const Person& p)
{
	Name = p.Name;
	Age = p.Age;
}
void Person::setName(string name)
{
	Name = name;
}
void Person::setAge(int age)
{
	Age = age;
}
string Person::getName(void)
{
	return Name;
}
int Person::getAge(void)
{
	return Age;
}
Person& Person::operator=(const Person& p)
{
	if (this == &p)
	{
		return *this;
	}
	Name = p.Name;
	Age = p.Age;
	return *this;
}
void Person::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		switch (e.command)
		{
		case cmGet:
			cout << "Èìÿ: " << getName() << endl;
			break;
		}
	}
}
