#include <C:\Users\aisha\OneDrive\������� ����\����������� ��������\laba_11\Zadacha_2\Money.h>
#include <iostream>
#include <stack> 
#include <vector> 
#include "Vector.h"
using namespace std;

int  main()
{
	setlocale(0, "Rus");

	//Vector<Money>v(3); 
	Vector<Money> v(3);
	v.Print();

	Money min = v.Min(); 
	cout << "\n������� ������� ��� ������� ������������ ��������: ";
	int pos; cin >> pos; 
	v.Add(min, pos);
	cout << "\n������� ����� ���������� ������������ �������� �� ������� " << pos << ":\n";
	v.Print();

	v.RemoveGreaterThanAverage();  // �������� ���� ���������, ������� �������� ���������������
	cout << "\n������� ����� �������� ��������� ������ �������� ���������������:\n";
	v.Print();  // ������ ���������� ���������


	v.MultiplyByMax();  // ��������� ������� �������� �� ������������
	cout << "\n������� ����� ��������� ������� �������� �� ������������:\n";
	v.Print();  // ������ ���������� ��������

	return 0;

}

