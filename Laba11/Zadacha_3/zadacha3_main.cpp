//������ ���� � ����� Time.h 
#include <C:\Users\aisha\OneDrive\������� ����\����������� ��������\laba_11\Zadacha_2\Money.h> 
#include "Vector.h"
#include <iostream> using namespace std;
void main()
{
	setlocale(0, "Rus");
	
	Vector<Money>vec(3);//������� ������ �� 5 ��������� 
	vec.Print();//������ �������
	Money min = vec.find_min();
	cout << "pos?"; int pos;
	cin >> pos;//������ ������� ��� ���������� 
	vec.Add(min, pos);//�������� ������� � ������ 
	cout << "������ ��������������� ������������ �������� �� ������� " << pos << ":\n";
	vec.Print();//������ �������
	vec.RemoveGreaterThanAverage();
	cout << "������ ����� �������� ��������� ������ �������� ���������������:\n ";
	vec.Print();//������ �������
	vec.MultiplyByMax();
	cout << "������ ����� ��������� ������� �������� �� ������������:\n";
	vec.Print();
}
