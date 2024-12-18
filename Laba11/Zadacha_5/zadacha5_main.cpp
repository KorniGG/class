#include <C:\Users\aisha\OneDrive\Рабочий стол\информатика полякова\laba_11\Zadacha_2\Money.h>
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
	cout << "\nВведите позицию для вставки минимального элемента: ";
	int pos; cin >> pos; 
	v.Add(min, pos);
	cout << "\nОчередь после добавления минимального элемента на позицию " << pos << ":\n";
	v.Print();

	v.RemoveGreaterThanAverage();  // Удаление всех элементов, больших среднего арифметического
	cout << "\nОчередь после удаления элементов больше среднего арифметического:\n";
	v.Print();  // Печать оставшихся элементов


	v.MultiplyByMax();  // Умножение каждого элемента на максимальный
	cout << "\nОчередь после умножения каждого элемента на максимальный:\n";
	v.Print();  // Печать измененных элементо

	return 0;

}

