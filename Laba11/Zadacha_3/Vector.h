#pragma once 
#include <vector> 
#include <iostream> 
using namespace std;
//шаблон класса 
template<class T> 
class Vector
{
	vector <T> v;//последовательный контейнер для хранения элементов вектора 
	int len;
public:
	Vector(void);//конструктор без параметра 
	Vector(int n);//конструктор с параметром 
	void Print();//печать
	~Vector(void);//деструктор

	T find_min();
	void Add(T el, int pos);
	T Srednee();
	void RemoveGreaterThanAverage();
	int Max();//найти номер максимальнго элемента
	void MultiplyByMax();



};
//конструктор без параметра 
template <class T> 
Vector<T>::Vector()
{
	len = 0;

}
//деструктор 
template <class T>
Vector<T>::~Vector(void)

{
}
//конструктор с параметром 
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
//печать
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
		std::cout << "Вектор пуст\n";
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
	T min_value = v[0]; // Инициализируем минимальное значение первым элементом
	for (int i = 1; i < v.size(); i++) {
		if (v[i] < min_value) {
			min_value = v[i]; // Обновляем минимальное значение, если текущее меньше
		}
	}
	return min_value; // Возвращаем минимальное значение
}

//добавление элемента 
template<class T>
void Vector<T>::Add(T el, int pos)
{
	v.insert(v.begin() + pos, el);

}

template<class T>
T Vector<T>::Srednee()
{
	if (v.empty()) return T(); // Возвращаем "нулевой" объект, если вектор пуст
	T s = v[0];
	for (int i = 1; i < v.size(); i++) s = s + v[i];
	int n = v.size();
	return s / n;
}

template<class T>
void Vector<T>::RemoveGreaterThanAverage()
{
	if (v.empty()) return; // Проверка на пустоту вектора

	T avg = Srednee(); // Вычисляем среднее арифметическое

	// Используем итератор для перебора элементов и удаления
	for (auto it = v.begin(); it != v.end();)
	{
		if (*it > avg) // Если элемент больше среднего арифметического
			it = v.erase(it); // Удаляем элемент и обновляем итератор
		else
			++it; // Переходим к следующему элементу
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
	if (v.empty()) return; // Проверка на пустой вектор

	// Находим максимальный элемент
	T maxElement = v[Max()];

	// Умножаем все элементы на максимальный
	for (int i = 0; i < v.size(); i++) {
		v[i] = v[i] * maxElement;
	}
}