#pragma once
#include <iostream>

class Iterator
{
	friend class Set;
	int* elem;
public:
    Iterator()
    {
        elem = 0;
    }
    Iterator(const Iterator& it)
    {
        elem = it.elem;
    }
    bool operator==(const Iterator& it)
    {
        return elem == it.elem;
    }
    bool operator!=(const Iterator& it)
    {
        return elem != it.elem;
    }
    void operator++()
    {
        ++elem;
    }
    void operator--()
    {
        --elem;
    }
    int& operator*() const
    {
        return *elem;
    }
};

class Set
{
	int size;
	int* data;
    Iterator beg;
    Iterator end;
public:
	Set(int);
	Set(const Set&);
	~Set();
	Set& operator=(const Set&);
	int& operator[](int);
	Set operator+(Set&);
	int operator()();
	friend std::istream& operator>>(std::istream& in, Set& a);
	friend std::ostream& operator<<(std::ostream& out, const Set& a);
    Iterator first()
    {
        return beg;
    }
    Iterator last()
    {
        return end;
    }

};
