#include <iostream> 
#include <vector> 
#include <cstdlib> 
using namespace std;

typedef vector<float>Vec;//определяем тип для работы с вектором
//функция для формирования вектора 
Vec make_vector(int n)
{
	Vec v;//пустой вектор 
	for(int i=0;i<n;i++)
	{
		float a = static_cast<float>(rand()) / RAND_MAX * 100 - 50; // Генерация случайного float от -50.0 до 49.999...
		v.push_back(a); // Добавляем a в конец вектора
	}
	return v;//возвращаем вектор как результа работы функции
}
//функция для печати вектора 
void print_vector(Vec v)
{
	for (size_t i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}



// Функция для поиска минимального значения в векторе
float find_min(Vec v) 
{
	if (v.empty()) throw "Vector is empty!"; // Исключение для пустого вектора
	float min_value = v[0]; // Инициализация минимального значения первым элементом
	for (size_t i = 1; i < v.size(); i++) {
		if (v[i] < min_value)
			min_value = v[i]; // Обновление минимального значения
	}
	return min_value;
}

void add_vector(Vec& v, float el, int pos)
{
	//добавляем на место pos элемент el
	v.insert(v.begin()+pos,el);
}

int srednee(Vec v)
{
	int s = 0;
	//перебор вектора
	for (int i = 0; i < v.size(); i++)
		s += v[i];
	int n = v.size();//количество элементов в векторе 
	return s / n;
}


// Функция для удаления элементов больше среднего арифметического
void remove_greater_than_avg(Vec& v)
{
	float avg = srednee(v); // находим среднее арифметическое
	for (auto it = v.begin(); it != v.end();)
	{
		if (*it > avg) // если элемент больше среднего
			it = v.erase(it); // удаляем элемент
		else
			++it; // переходим к следующему элементу
	}
}

// Функция для поиска максимального значения в векторе
float find_max(Vec v)
{
	if (v.empty()) throw "Vector is empty!"; // Исключение для пустого вектора
	float max_value = v[0]; // Инициализация максимального значения первым элементом
	for (size_t i = 1; i < v.size(); i++)
	{
		if (v[i] > max_value)
			max_value = v[i]; // Обновление максимального значения
	}
	return max_value;
}

// Функция для умножения каждого элемента на максимальный элемент вектора
void multiply_by_max(Vec& v)
{
	float max_val = find_max(v); // находим максимальный элемент
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] *= max_val; // умножаем каждый элемент на максимальный
	}
}

//основная функция 
void main()
{
	setlocale(0, "Rus");
	srand(static_cast<unsigned>(time(0)));
	try
	{
		vector<float> v;//вектор

		vector<float>::iterator vi = v.begin();//итератор 
		int n;
		cout << "N?"; cin >> n; 
		v = make_vector(n);//формирование вектора 
		print_vector(v);//печать вектора
		float el= find_min(v);
		//позиция для вставки 
		cout<<"pos?"; 
		int pos; 
		cin>>pos;
		//генерируем ошибку, если позиция для вставки больше размера вектора 
		if(pos>v.size())throw 1;
		//вызов функции для добавления 
		add_vector(v,el,pos);
		//печать вектора
		cout << "Вектор после добавления минимального элемента на позицию " << pos << ":\n";
		print_vector(v);
		remove_greater_than_avg(v);
		cout << "Вектор после удаления элементов больше среднего арифметического:\n ";
		print_vector(v); // печать вектора после удаления элементов
		multiply_by_max(v);
		cout << "Вектор после умножения каждого элемента на максимальный:\n";
		print_vector(v);

	}
	catch (int)//блок обработки ошибок
	{
		cout << "error!";
	}
}
