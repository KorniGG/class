#pragma once
#include <iostream>
#include <string> 
using namespace std; 

class Exam
{
	//��������
	string FIO;
	string predmet;
	int ocenka;
public:
	Exam();//����������� ��� ����������
	Exam(string, string, int);//����������� � �����������
	Exam(const Exam&);//����������� � ������������
	~Exam(); //����������
	string get_FIO();//���������
	void set_FIO(string);//������������
	string get_predmet();//���������
	void set_predmet(string); //������������
	int get_ocenka(); //���������
	void set_ocenka(int); //������������
	void show();//�������� ���������
};

