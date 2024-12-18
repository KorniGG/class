#include "Exam.h"
#include <iostream>
#include <string> 
using namespace std;

//функция для возврата объекта как результата 
Exam make_exam()
{
	string f;
	string p;
	int o;
	cout << "Vvedite FIO:";
	getline(cin, f);
	cout << "Vvedite predmet: ";
	getline(cin, p);
	cout << "Vvedite ocenka: ";
	cin >> o;
	Exam t(f, p, o);
	return t;
}
//функция для передачи объекта как параметра 
void print_exam(Exam e)
{
	e.show();
}
void main()
{
	//конструктор без параметров 
	Exam e1;
	e1.show();
	//коструктор с параметрами
	Exam e2("Alapanov Islam Alekseevich", "drama theory", 5);
	e2 . show () ;
	//конструктор копирования 
	Exam e3=e2 ;
	e3.set_FIO("Alapanova Aisha Alekseevna");
	e3.set_predmet("theoretical mechanics");
	e3.set_ocenka(4);
	//конструктор копирования 
	print_exam(e3);
	//конструктор копирования
	e1=make_exam();
	e1.show () ;
}
