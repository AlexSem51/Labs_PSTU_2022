#pragma once
#include <iostream>
#include <string>
using namespace std;

class Error
{
public:
	virtual void what() {};
};

class IndexError : public Error
{
protected:
	string msg;
public:
	IndexError() { msg = "Ошибка индексации\n"; }
	virtual void what() { cout << msg; }
};

class SizeError : public Error
{
protected:
	string msg;
public:
	SizeError()  { msg = "Ошибка размера множества\n"; }
	virtual void what() { cout << msg; }
};

class MaxSizeError : public SizeError
{
protected:
	string msg_M;
public:
	MaxSizeError() { 
		SizeError();
		msg_M = "Размер множества > MaxSize\n";
	}
	virtual void what() { cout << msg << msg_M; }
};

class EmptySizeError : public SizeError
{
protected:
	string msg_E;
public:
	EmptySizeError() {
		SizeError();
		msg_E =  "Множество пустое\n";
	}
	virtual void what() { cout << msg << msg_E; }
};

class IndexError0 : public IndexError
{
protected:
	string msg_0;
public:
	IndexError0() {
		IndexError();
		msg_0 = "Индекс < 0\n";
	}
	virtual void what() { cout << msg << msg_0; }
};

class IndexErrorS : public IndexError
{
protected:
	string msg_S;
public:
	IndexErrorS() {
		IndexError();
		msg_S = "Индекс > размера множества\n";
	}
	virtual void what() { cout << msg << msg_S; }
};








