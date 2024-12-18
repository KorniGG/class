#pragma once
#include "Magazin.h"
#include "Object.h"

class List {
public:
	List();
	List(int);
	~List(void);

	void Add();
	void Del();
	void Show();
	void Get_Name();
	int operator()();
protected:
	Object** beg;
	int size;
	int cur;
};