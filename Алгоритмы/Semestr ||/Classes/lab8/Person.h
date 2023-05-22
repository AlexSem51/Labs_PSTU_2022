#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class Person : public Object
{
protected:
	string Name;
	int Age;
public:
	Person(void);
	virtual ~Person(void);
	void Show(void);
	void Input(void);
	Person(string, int);
	Person(const Person&);
	void setName(string);
	void setAge(int);
	string getName(void);
	int getAge(void);
	Person& operator=(const Person&);
	void HandleEvent(const TEvent&);
};
