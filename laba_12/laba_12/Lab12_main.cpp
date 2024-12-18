#include <iostream>
#include <map>
using namespace std;

typedef multimap<int, float> TMap; // Определяем тип для работы с multimap
typedef TMap::iterator it;        // Итератор

// Функция для формирования multimap
TMap make_map(int n)
{
    TMap m; // Пустой контейнер
    float a;
    for (int i = 0; i < n; i++)
    {
        cout << "?";
        cin >> a;
        // Создаем пару и добавляем ее в multimap
        m.insert(make_pair(i, a));
    }
    return m; // Возвращаем контейнер
}

// Функция для печати multimap
void print_map(TMap m)
{
    for (auto& p : m)
        cout << p.first << " : " << p.second << endl;
}

// Вычисление среднего арифметического
float srednee(TMap v)
{
    float s = 0;
    int n = 0; // Счетчик элементов
    for (auto& p : v)
    {
        s += p.second;
        n++;
    }
    return n > 0 ? s / n : 0;
}

// Поиск ключа максимального элемента
int Max(TMap v)
{
    it i = v.begin();
    int nom = i->first;
    float m = i->second; // Значение первого элемента

    for (auto& p : v)
    {
        if (p.second > m)
        {
            m = p.second;
            nom = p.first;
        }
    }
    return nom; // Возвращаем ключ max
}

// Поиск минимального значения
float Min(TMap v)
{
    if (v.empty())
    {
        throw runtime_error("Контейнер пуст. Невозможно найти минимальный элемент.");
    }

    it i = v.begin();
    float m = i->second; // Значение первого элемента

    for (auto& p : v)
    {
        if (p.second < m)
        {
            m = p.second;
        }
    }
    return m; // Возвращаем минимальное значение
}

// Добавление минимального элемента на заданную позицию
void addMinElement(TMap& m, int pos, float minValue) {
    TMap newMap;
    int currentIndex = 0;

    for (auto it = m.begin(); it != m.end(); ++it) {
        if (currentIndex == pos) {
            newMap.insert(make_pair(pos, minValue)); // Добавляем минимальный элемент на указанную позицию
        }
        newMap.insert(make_pair(currentIndex, it->second)); // Вставляем текущий элемент
        currentIndex++;
    }

    if (pos >= currentIndex) {
        newMap.insert(make_pair(pos, minValue)); // Добавляем в конец, если позиция за пределами текущего размера
    }

    m = newMap; // Заменяем оригинальный контейнер
}


// Удаление элементов, значения которых больше среднего
void removeAboveAverage(TMap& v)
{
    float average = srednee(v);

    for (auto it = v.begin(); it != v.end();)
    {
        if (it->second > average)
        {
            it = v.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

// Умножение каждого элемента на максимальный
void multiplyByMax(TMap& v)
{
    int maxIndex = Max(v);
    float maxValue = v.find(maxIndex)->second;

    for (auto& item : v)
    {
        item.second *= maxValue;
    }
}

// Основная функция
int main()
{
    setlocale(0, "Rus");
    int n;
    cout << "N?";
    cin >> n; // Количество элементов
    TMap m = make_map(n); // Создать контейнер
    print_map(m);         // Напечатать контейнер

    float min = Min(m);
    cout << "\nМинимальное значение: " << min << "\n";

    cout << "pos?";
    int pos;
    cin >> pos;
    addMinElement(m, pos, min);
    cout << "После добавления минимального элемента на позицию " << pos << ":\n";
    print_map(m);

    removeAboveAverage(m);
    cout << "\nПосле удаления элементов больше среднего арифметического:\n";
    print_map(m);

    multiplyByMax(m);
    cout << "\nПосле умножения каждого элемента на максимальный:\n";
    print_map(m);

    return 0;
}
