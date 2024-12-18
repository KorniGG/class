#pragma once
#include <iostream>
#include <string> 
using namespace std; 

class Exam
{
	//атрибуты
	string FIO;
	string predmet;
	int ocenka;
public:
	Exam();//конструктор без параметров
	Exam(string, string, int);//конструктор с параметрами
	Exam(const Exam&);//конструктор с копированием
	~Exam(); //деструктор
	string get_FIO();//селекторы
	void set_FIO(string);//модификаторы
	string get_predmet();//селекторы
	void set_predmet(string); //модификаторы
	int get_ocenka(); //селекторы
	void set_ocenka(int); //модификаторы
	void show();//просмотр атрибутов
};

