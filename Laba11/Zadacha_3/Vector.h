#pragma once 
#include <vector> 
#include <iostream> 
using namespace std;
//������ ������ 
template<class T> 
class Vector
{
	vector <T> v;//���������������� ��������� ��� �������� ��������� ������� 
	int len;
public:
	Vector(void);//����������� ��� ��������� 
	Vector(int n);//����������� � ���������� 
	void Print();//������
	~Vector(void);//����������

	T find_min();
	void Add(T el, int pos);
	T Srednee();
	void RemoveGreaterThanAverage();
	int Max();//����� ����� ������������ ��������
	void MultiplyByMax();



};
//����������� ��� ��������� 
template <class T> 
Vector<T>::Vector()
{
	len = 0;

}
//���������� 
template <class T>
Vector<T>::~Vector(void)

{
}
//����������� � ���������� 
template <class T> 
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a; v.push_back(a);
	}
	len = v.size();
}
//������
//template <class T> 
//void Vector<T>::Print()
//{
//	for (int i = 0; i < v.size(); i++) cout << v[i] << "	";
//	cout << endl;
//}

template<class T>
void Vector<T>::Print()
{
	if (v.empty()) {
		std::cout << "������ ����\n";
		return;
	}
	for (const auto& el : v) {
		std::cout << el << " ";
	}
	std::cout << std::endl;
}


template<class T>
T Vector<T>::find_min()
{
	T min_value = v[0]; // �������������� ����������� �������� ������ ���������
	for (int i = 1; i < v.size(); i++) {
		if (v[i] < min_value) {
			min_value = v[i]; // ��������� ����������� ��������, ���� ������� ������
		}
	}
	return min_value; // ���������� ����������� ��������
}

//���������� �������� 
template<class T>
void Vector<T>::Add(T el, int pos)
{
	v.insert(v.begin() + pos, el);

}

template<class T>
T Vector<T>::Srednee()
{
	if (v.empty()) return T(); // ���������� "�������" ������, ���� ������ ����
	T s = v[0];
	for (int i = 1; i < v.size(); i++) s = s + v[i];
	int n = v.size();
	return s / n;
}

template<class T>
void Vector<T>::RemoveGreaterThanAverage()
{
	if (v.empty()) return; // �������� �� ������� �������

	T avg = Srednee(); // ��������� ������� ��������������

	// ���������� �������� ��� �������� ��������� � ��������
	for (auto it = v.begin(); it != v.end();)
	{
		if (*it > avg) // ���� ������� ������ �������� ���������������
			it = v.erase(it); // ������� ������� � ��������� ��������
		else
			++it; // ��������� � ���������� ��������
	}
}

template <class T> int Vector<T>::Max()
{
	T m = v[0];
	int n = 0;
	for (int i = 1; i < v.size(); i++) if (v[i] > m)
	{
		m = v[i]; n = i;
	}
	return n;
}

template <class T>
void Vector<T>::MultiplyByMax()
{
	if (v.empty()) return; // �������� �� ������ ������

	// ������� ������������ �������
	T maxElement = v[Max()];

	// �������� ��� �������� �� ������������
	for (int i = 0; i < v.size(); i++) {
		v[i] = v[i] * maxElement;
	}
}