#include <iostream>
#include <C:\Users\aisha\OneDrive\Рабочий стол\информатика полякова\laba_11\Zadacha_2\Money.h>
#include <cstdlib>
#include <map>
using namespace std;

typedef multimap<int, Money> TMap; // Используем multimap вместо map
typedef TMap::iterator it;

// Функция для формирования словаря
TMap make_map(int n) {
    TMap m; // Пустой словарь
    Money a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        // Создаём пару и добавляем её в словарь
        m.insert(make_pair(i, a));
    }
    return m; // Возвращаем словарь как результат работы функции
}

// Функция для печати словаря
void print_map(TMap m) {
    for (it i = m.begin(); i != m.end(); i++) {
        cout << i->first << " - " << i->second << " " << endl;
    }
}

// Вычисление среднего арифметического
Money srednee(TMap m) {
    Money s = m.begin()->second; // Первый элемент – начальное значение суммы
    // Перебор словаря
    for (it i = next(m.begin()); i != m.end(); i++) {
        s = s + i->second;
    }
    int n = m.size(); // Количество элементов в словаре
    return s / n;
}

// Поиск максимального элемента
int Max(TMap v) {
    it i = v.begin();
    int nom = 0, k = 0;
    Money m = i->second; // Значение первого элемента
    while (i != v.end()) {
        if (m < i->second) {
            m = i->second;
            nom = k;
        }
        i++; // Итератор
        k++; // Счётчик элементов
    }
    return nom; // Номер max
}

// Поиск минимального элемента
int Min(TMap v) {
    it i = v.begin();
    int nom = 0, k = 0;
    Money m = i->second; // Значение первого элемента
    while (i != v.end()) {
        if (m > i->second) {
            m = i->second;
            nom = k;
        }
        i++; // Итератор
        k++; // Счётчик элементов
    }
    return nom; // Номер min
}

//Найти минимальный элемент и добавить его на заданную позицию контейнера
void add_min_to_position(TMap& v, int pos) {
    // Проверяем корректность позиции
    if (pos < 0 || pos > v.size()) {
        cout << "Ошибка: некорректная позиция." << endl;
        return;
    }

    // Находим минимальное значение
    it min_it = v.begin();
    for (it i = v.begin(); i != v.end(); ++i) {
        if (i->second < min_it->second) {
            min_it = i;
        }
    }
    Money min_value = min_it->second;

    // Добавляем минимальное значение с заданным ключом (симулируем позицию)
    v.insert(make_pair(pos, min_value));
}

//Найти элементы большие среднего арифметического и удалить их из контейнера
void removeGreaterThanAverage(TMap& m) {
    // Вычисляем среднее арифметическое
    Money average = srednee(m);

    // Проходим по контейнеру и удаляем элементы, которые больше среднего
    for (auto it = m.begin(); it != m.end(); ) {
        if (it->second > average) {
            it = m.erase(it); // Удаляем текущий элемент и обновляем итератор
        }
        else {
            ++it; // Переходим к следующему элементу
        }
    }
}

void multiplyByMax(TMap& m) {
    // Поиск максимального значения
    Money maxValue = m.begin()->second; // Начинаем с первого элемента
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second > maxValue) {
            maxValue = it->second;
        }
    }

    // Умножаем каждый элемент на максимальное значение
    for (auto it = m.begin(); it != m.end(); ++it) {
        it->second = it->second * maxValue;
    }
}



// Основная функция
int main() {

    setlocale(0, "Rus");
    int n;
    cout << "N? ";
    cin >> n;
    TMap m = make_map(n); // Создать словарь
    print_map(m); // Напечатать словарь


    //позиция для вставки 
    cout << "pos?";
    int pos;
    cin >> pos;
    add_min_to_position(m, pos);
    cout << "после добавления минимального элемента на позицию " << pos << ":\n";
    print_map(m);

    removeGreaterThanAverage(m);
    cout << "\nПосле удаления элементов больше среднего арифметического:\n";
    print_map(m);

    multiplyByMax(m);
    cout << "\nПосле умножения каждого элемента на максимальный:\n";
    print_map(m);



}
