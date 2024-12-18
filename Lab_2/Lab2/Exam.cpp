#include "Exam.h"
#include <iostream>
#include <string> 
using namespace std;

//����������� ��� ����������
Exam::Exam()
{
	FIO = " ";
	predmet = " ";
	ocenka =  0;
	cout << "Constructor bez parametrov dlia objecta" << this << endl;
}
//����������� � �����������
Exam::Exam(string F, string P, int O)
{
	FIO = F;
	predmet = P;
	ocenka = O;
	cout << "Constructor s parametrami dlia objecta" << this << endl;
}
//����������� � ������������
Exam::Exam(const Exam& e)
{
	FIO = e.FIO;
	predmet = e.predmet;
	ocenka = e.ocenka;
	cout << "Constructor copirovania dlia objecta" << this << endl;
}

//����������
Exam:: ~Exam()
{
	cout << "Destructor dlia objecta" << this << endl;
}
//���������
string Exam::get_FIO()
{
	return FIO;
}
string Exam::get_predmet()
{
	return predmet;
}
int Exam::get_ocenka()
{
	return ocenka;
}
//������������
void Exam::set_FIO(string F)
{
	FIO = F;
}
void Exam::set_predmet(string P)
{
	predmet = P;
}
void Exam::set_ocenka(int O)
{
	ocenka = O;
}
//����� ��� ��������� ���������	
void Exam::show()
{
	cout << "FIO : " << FIO << endl;
	cout << "predmet :" << predmet << endl;
	cout << "ocenka : " << ocenka << endl;
}

