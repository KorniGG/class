#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template<class T>
class Vector {
    priority_queue<T> s;  // Контейнер (очередь с приоритетом)
    int len;              // Размер контейнера
public:
    Vector();                      // Конструктор без параметров
    Vector(int n);                  // Конструктор с параметром
    Vector(const Vector<T>& Vec);   // Конструктор копирования
    void Print();                   // Печать

    T Min();
    void Add(T el, int pos);
    T Srednee();
    void RemoveGreaterThanAverage();
    T Max();
    void MultiplyByMax();
};

// Копирование очереди с приоритетом в вектор
template <class T>
vector<T> copy_queue_to_vector(priority_queue<T> s) {
    vector<T> v;
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    return v;
}

// Копирование вектора в очередь с приоритетом
template <class T>
priority_queue<T> copy_vector_to_queue(vector<T> v) {
    priority_queue<T> s;
    for (int i = 0; i < v.size(); i++) {
        s.push(v[i]);
    }
    return s;
}

// Конструктор без параметров
template <class T>
Vector<T>::Vector() {
    len = 0;
}

// Конструктор с параметром
template <class T>
Vector<T>::Vector(int n) {
    T a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        s.push(a);  // Добавить в очередь с приоритетом элемент
    }
    len = s.size();
}

// Конструктор копирования
template <class T>
Vector<T>::Vector(const Vector<T>& Vec) {
    len = Vec.len;
    // Копируем значения очереди с приоритетом Vec.s в вектор v
    vector<T> v = copy_queue_to_vector(Vec.s);
    // Копируем вектор v в очередь с приоритетом s
    s = copy_vector_to_queue(v);
}

// Печать
template <class T>
void Vector<T>::Print() {
    // Создаем временную копию очереди с приоритетом для печати
    priority_queue<T> temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";  // Выводим элемент из вершины очереди
        temp.pop();  // Удаляем элемент из временной очереди
    }
}

// Поиск минимального элемента
template <class T>
T Vector<T>::Min() {
    T m = s.top();
    vector<T> v = copy_queue_to_vector(s);
    while (!s.empty()) {
        if (s.top() < m) m = s.top();
        s.pop();
    }
    s = copy_vector_to_queue(v);
    return m;
}

// Добавление элемента el в очередь на позицию pos
template <class T>
void Vector<T>::Add(T el, int pos) {
    vector <T> v; // Вспомогательный вектор
    int i = 1;
    vector<T> tmp = copy_queue_to_vector(s); // Копируем очередь в вектор
    while (!tmp.empty()) {
        if (i == pos) v.push_back(el);  // Если номер позиции совпадает, добавляем новый элемент
        v.push_back(tmp.back());  // Добавляем элемент в вектор
        tmp.pop_back();  // Удаляем элемент из вектора
        i++;
    }
    s = copy_vector_to_queue(v);  // Копируем вектор обратно в очередь с приоритетом
}

// Среднее арифметическое
template <class T>
T Vector<T>::Srednee() {
    vector<T> v = copy_queue_to_vector(s);
    int n = 1;  // Количество элементов в очереди
    T sum = s.top();  // Начальное значение для суммы
    s.pop();  // Удаляем элемент из вершины очереди
    while (!s.empty()) {
        sum = sum + s.top();  // Добавляем в сумму элемент из вершины очереди
        s.pop();  // Удаляем элемент из вершины очереди
        n++;  // Увеличиваем количество элементов
    }
    s = copy_vector_to_queue(v);  // Копируем вектор обратно в очередь с приоритетом
    return sum / n;
}

template <class T>
void Vector<T>::RemoveGreaterThanAverage() {
    // Сначала вычисляем среднее арифметическое
    T average = Srednee();

    // Копируем очередь в вектор
    vector<T> v = copy_queue_to_vector(s);

    // Создаем новый контейнер для сохранения элементов, которые меньше или равны среднему
    priority_queue<T> new_queue;

    // Проходим по всем элементам вектора
    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] <= average) {
            new_queue.push(v[i]);  // Если элемент меньше или равен среднему, добавляем в новый контейнер
        }
    }

    // Копируем элементы обратно в оригинальную очередь
    s = new_queue;
}

// Поиск максимального элемента
template <class T>
T Vector<T>::Max() {
    T m = s.top();  // m присвоить значение из вершины очереди
    vector<T> v = copy_queue_to_vector(s);
    while (!s.empty()) {
        if (s.top() > m) m = s.top();
        s.pop();  // Удаляем элемент из вершины очереди
    }
    s = copy_vector_to_queue(v);  // Копируем вектор обратно в очередь с приоритетом
    return m;
}

template <class T>
void Vector<T>::MultiplyByMax() {
    // Находим максимальный элемент
    T max_val = Max();

    // Копируем очередь в вектор
    vector<T> v = copy_queue_to_vector(s);

    // Создаем новый контейнер для хранения измененных элементов
    priority_queue<T> new_queue;

    // Проходим по всем элементам вектора и умножаем их на максимальный элемент
    for (int i = v.size() - 1; i >= 0; i--) {
        new_queue.push(v[i] * max_val);  // Умножаем элемент на максимальный
    }

    // Копируем новый контейнер обратно в оригинальную очередь
    s = new_queue;
}

