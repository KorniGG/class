#include <iostream> 
#include <vector> 
#include <cstdlib> 
#include "Money.h" 
using namespace std;

typedef vector<Money>Vec;//определяем тип для работы с вектором
//функция для формирования вектора 
Vec make_vector(int n)
{
	Vec v;//пустой вектор 
	for (int i = 0; i < n; i++)
	{
		long r = rand() % 10;
		int k = rand() % 100;
		Money a(r, k);
		v.push_back(a);
	}
	return v;//возвращаем вектор как результа работы функции
}

//функция для печати вектора 
void print_vector(Vec v)
{
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;
}

// Функция для поиска минимального значения в векторе
float find_min(const Vec& v)
{
	if (v.empty()) throw "Vector is empty!"; // Исключение для пустого вектора

	float min_value = static_cast<float>(v[0]); // Преобразуем Money в float
	for (size_t i = 1; i < v.size(); i++) {
		if (static_cast<float>(v[i]) < min_value) // Сравниваем как float
			min_value = static_cast<float>(v[i]); // Обновляем минимальное значение
	}
	return min_value;
}

void add_vector(Vec& v, float el, int pos)
{
	// Преобразуем float в Money
	long rubles = static_cast<long>(el);       // Целая часть — рубли
	int kop = static_cast<int>((el - rubles) * 100); // Дробная часть — копейки
	Money new_money(rubles, kop);

	// Вставляем Money в вектор
	v.insert(v.begin() + pos, new_money);
}

Money srednee(Vec v)
{
	if (v.empty()) throw "Vector is empty!";

	long total_kop = 0; // Сумма всех значений в копейках
	for (const auto& money : v) {
		total_kop += money.get_rub() * 100 + money.get_kop(); // Переводим в копейки и суммируем
	}

	long avg_kop = total_kop / v.size(); // Среднее значение в копейках

	return Money(avg_kop / 100, avg_kop % 100); // Преобразуем обратно в рубли и копейки
}



// Функция для удаления элементов больше среднего арифметического
void remove_greater_than_avg(Vec& v)
{
	Money avg = srednee(v); // Находим среднее арифметическое

	for (auto it = v.begin(); it != v.end();)
	{
		if (*it > avg) // Сравниваем элементы с помощью перегруженного оператора `>`
			it = v.erase(it); // Удаляем элемент, если он больше среднего
		else
			++it; // Переходим к следующему элементу
	}
}

// Функция для поиска максимального значения в векторе
Money find_max(const Vec& v)
{
	if (v.empty()) throw "Vector is empty!"; // Исключение для пустого вектора
	Money max_value = v[0]; // Инициализация максимального значения первым элементом
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
	if (v.empty()) throw "Vector is empty!"; // Исключение для пустого вектора
	Money max_val = find_max(v); // Находим максимальный элемент
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] = v[i] * max_val; // Умножаем каждый элемент на максимальный
	}
}


//основная функция

void main()
{
	try
	{
		setlocale(0, "Rus");
		srand(static_cast<unsigned>(time(0)));
		vector<Money> v;  // Вектор объектов типа Money
		vector<Money>::iterator vi = v.begin();
		int n;
		cout << "N?";
		cin >> n;  // Вводим количество элементов в векторе

		// Формируем вектор
		v = make_vector(n);

		// Печатаем вектор
		print_vector(v);
		float el = find_min(v);
		//позиция для вставки 
		cout << "pos?";
		int pos;
		cin >> pos;
		//генерируем ошибку, если позиция для вставки больше размера вектора 
		if (pos > v.size())throw 1;
		//вызов функции для добавления 
		add_vector(v, el, pos);
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
	catch (int)  // Обработка ошибок
	{
		cout << "error!";
	}

}
