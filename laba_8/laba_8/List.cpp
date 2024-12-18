#include "List.h"

List::List() {
	beg = nullptr;
	size = 0;
	cur = 0;
}

List::~List(void) {
	if (beg != 0) delete[] beg;
	beg = 0;
}

List::List(int n) {
	beg = new Object * [n];
	cur = 0;
	size = n;
}

void List::Get_Name() {
	Object** p = beg;
	for (int i = 0; i < cur; i++) {
		cout << (*p)->Get_name() << endl;
		p++;
	}
}

void List::Add() {
	Object* p;
	cout << "1.ПЕЧАТНОЕ ИЗДАНИЕ" << endl;
	cout << "2.ЖУРНАЛ " << endl;
	int y;
	cin >> y;
	if (y == 1) { 
		Print* a = new (Print);
		a->Input(); 
		p = a;
		if (cur < size) {
			beg[cur] = p;
			cur++;
		}
	}
	else if (y == 2) {
		Magazin* b = new Magazin;
		b->Input();
		p = b;
		if (cur < size) {
			beg[cur] = p;
			cur++;
		}
	}
	else return;
}

void List::Show() {
	if (cur == 0) cout << "Пусто" << endl;
	Object** p = beg; 
	for (int i = 0; i < cur; i++) {
		(*p)->Show();  
		p++; 
	}
}

int List::operator ()() {
	return cur;
}

void List::Del() {
	if (cur == 0) return;
	cur--;
}