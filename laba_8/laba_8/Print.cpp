#include "Print.h"

Print::~Print(void) {}

Print::Print(void) {
	name = "неизвестно";
	author = "аноним";
}

Print::Print(string N, string A) {
	name = N;
	author = A;
}

Print::Print(const Print& P) {
	name = P.name;
	author = P.author;
}


void Print::Show() {
	cout << "\nНазвание: " << name;
	cout << "\nАвтор: " << author << endl;
}

void Print::Input() {
	getline(cin, name);
	cout << "Введите название: "; getline(cin, name);
	cout << "Введите автора: "; getline(cin, author);
}

Print& Print::operator=(const Print& p) {
	if (&p == this) return *this;
	name = p.name;
	author = p.author;
	return *this;
}