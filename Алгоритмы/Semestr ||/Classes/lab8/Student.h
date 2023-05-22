#pragma once
#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

class Student : public Person
{
protected:
	float Rating;
public:
	Student(void);
	~Student(void);
	void Show();
	void Input();
	Student(string, int, float);
	Student(const Student&);
	void setRating(float);
	float getRating(void);
	Student& operator=(const Student&);
};
