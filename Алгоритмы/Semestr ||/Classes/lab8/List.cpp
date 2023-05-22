#include <iostream>
#include "List.h"
#include "Student.h"
using namespace std;

List::List(void)
{
	beg = nullptr;
	size = 0;
	cur = 0;
}
List::List(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
List::~List(void)
{
	if (beg != 0)
	{
		delete[] beg;
	}
	beg = 0;
}
void List::Add(void)
{
	Object* tmp;
	cout << "1.×åëîâåê " << " èëè " << "2.Ñòóäåíò" << endl;
	int c;
	cin >> c;
	if (c == 1)
	{
		Person* p = new Person;
		p->Input();
		tmp = p;
		if (cur < size)
		{
			beg[cur] = tmp;
			cur++;
		}
	}
	else if (c == 2)
	{
		Student* s = new Student;
		s->Input();
		tmp = s;
		if (cur < size)
		{
			beg[cur] = tmp;
			cur++;
		}
	}
	else
	{
		return;
	}
}
void List::Show()
{
	if (cur == 0)
	{
		cout << "Ïóñòî" << endl;
	}
	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();
		p++;
	}
}
int List::operator()()
{
	return cur;
}
void List::Del(void)
{
	if (cur == 0)
	{
		return;
	}
	cur--;
}
void List::Find(int tmp)
{
	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		if (i == tmp - 1)
		{
			(*p)->Show();
		}
		p++;
	}
}
void List::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e);
			p++;
		}
	}
}
