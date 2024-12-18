//полный путь к файлу Time.h 
#include <C:\Users\aisha\OneDrive\Рабочий стол\информатика полякова\laba_11\Zadacha_2\Money.h> 
#include "Vector.h"
#include <iostream> using namespace std;
void main()
{
	setlocale(0, "Rus");
	
	Vector<Money>vec(3);//создать вектор из 5 элементов 
	vec.Print();//печать вектора
	Money min = vec.find_min();
	cout << "pos?"; int pos;
	cin >> pos;//ввести позицию для добавления 
	vec.Add(min, pos);//добавить элемент в вектор 
	cout << "Вектор последобавления минимального элемента на позицию " << pos << ":\n";
	vec.Print();//печать вектора
	vec.RemoveGreaterThanAverage();
	cout << "Вектор после удаления элементов больше среднего арифметического:\n ";
	vec.Print();//печать вектора
	vec.MultiplyByMax();
	cout << "Вектор после умножения каждого элемента на максимальный:\n";
	vec.Print();
}
