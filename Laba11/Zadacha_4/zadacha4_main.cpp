#include <C:\Users\aisha\OneDrive\Рабочий стол\информатика полякова\laba_11\Zadacha_2\Money.h>
#include <iostream>
#include <queue>  // Подключаем очередь с приоритетами
#include <vector>
using namespace std;

typedef priority_queue<Money> PQ;  // Очередь с приоритетами для объектов Money
typedef vector<Money> Vec;  // Вектор для объектов Money

// Функция для создания очереди с приоритетами
PQ make_priority_queue(int n) {
    PQ pq;
    Money m;
    for (int i = 0; i < n; i++) {
        cin >> m;  // Ввод элемента
        pq.push(m); // Добавление в очередь с приоритетами
    }
    return pq;
}

// Функция для печати очереди с приоритетами
void print_priority_queue(PQ pq) {
    PQ temp = pq;
    while (!temp.empty()) {
        cout << temp.top() << " ";  // Вывод элемента
        temp.pop();  // Убираем его из очереди
    }
    cout << endl;
}

// Копирует очередь с приоритетами в вектор
Vec copy_priority_queue_to_vector(PQ pq) {
    Vec v;
    while (!pq.empty()) {
        v.push_back(pq.top());  // Добавить элемент с наивысшим приоритетом
        pq.pop();
    }
    return v;
}

// Копирует вектор в очередь с приоритетами
PQ copy_vector_to_priority_queue(Vec v) {
    PQ pq;
    for (int i = 0; i < v.size(); i++) {
        pq.push(v[i]);
    }
    return pq;
}

// Поиск минимального элемента в очереди с приоритетами
Money Min(PQ pq) {
    Money m = pq.top();  // Инициализируем минимальный элемент первым элементом
    PQ temp = pq;  // Создаем копию очереди
    while (!temp.empty()) {
        if (temp.top() < m) {
            m = temp.top();  // Обновляем минимальный элемент
        }
        temp.pop();
    }
    return m;
}

// Добавление элемента в очередь с приоритетами на указанную позицию
void Add_to_priority_queue(PQ& pq, Money el, int pos) {
    Vec v = copy_priority_queue_to_vector(pq);  // Копируем очередь в вектор
    if (pos < 1 || pos > v.size() + 1) {
        cout << "Неверная позиция!" << endl;
        return;
    }
    v.insert(v.begin() + pos - 1, el);  // Вставляем элемент на позицию (нумерация с 1)
    pq = copy_vector_to_priority_queue(v);  // Копируем вектор обратно в очередь с приоритетами
}

// Вычисление среднего значения
Money Srednee(PQ pq) {
    Vec v = copy_priority_queue_to_vector(pq);  // Копируем очередь в вектор
    int n = 1;
    Money sum = pq.top();  // Начальное значение для суммы
    pq.pop();  // Удалить первый элемент
    while (!pq.empty()) {  // Пока очередь не пуста
        sum = sum + pq.top();  // Добавить в сумму элемент
        pq.pop();  // Удалить элемент
        n++;
    }
    pq = copy_vector_to_priority_queue(v);  // Восстанавливаем очередь
    return sum / n;  // Возвращаем среднее арифметическое
}

// Удаление элементов больше среднего арифметического
void RemoveGreaterThanAverage(PQ& pq) {
    Money average = Srednee(pq);  // Получаем среднее арифметическое
    Vec v = copy_priority_queue_to_vector(pq);  // Копируем очередь в вектор
    PQ new_pq;  // Новая очередь для элементов, не превышающих среднее

    // Проходим по всем элементам вектора и добавляем в новую очередь только те, которые меньше или равны среднему
    for (int i = 0; i < v.size(); i++) {
        if (v[i] <= average) {
            new_pq.push(v[i]);
        }
    }

    // Перезаписываем очередь новой
    pq = new_pq;
}

// Поиск максимального элемента в очереди с приоритетами
Money Max(PQ pq) {
    Money m = pq.top();  // Переменной m присваиваем значение из вершины
    PQ temp = pq;  // Создаем копию очереди
    while (!temp.empty()) {  // Пока очередь не пуста
        if (temp.top() > m) m = temp.top();  // Сравниваем m и элемент
        temp.pop();  // Удаляем элемент из очереди
    }
    return m;  // Возвращаем m
}

// Умножение каждого элемента на максимальный элемент
void MultiplyByMax(PQ& pq) {
    Money max_elem = Max(pq);  // Находим максимальный элемент
    Vec v = copy_priority_queue_to_vector(pq);  // Копируем очередь в вектор
    PQ new_pq;  // Новая очередь для хранения результатов

    // Проходим по всем элементам вектора и умножаем их на максимальный элемент
    for (int i = 0; i < v.size(); i++) {
        Money result = v[i] * max_elem;  // Умножаем элемент на максимальный
        new_pq.push(result);  // Добавляем результат в новую очередь
    }

    // Перезаписываем очередь новыми значениями
    pq = new_pq;
}

int main() {
    setlocale(0, "Rus");

    Money m;
    PQ pq;
    int n;
    cout << "Введите количество элементов в очереди с приоритетами: ";
    cin >> n;

    pq = make_priority_queue(n);  // Создать очередь с приоритетами
    cout << "Исходная очередь с приоритетами:\n";
    print_priority_queue(pq);  // Печать очереди с приоритетами

    m = Min(pq);  // Находим минимальный элемент
    cout << "Минимальный элемент: " << m << endl;

    cout << "Введите позицию для вставки минимального элемента: ";
    int pos;
    cin >> pos;

    // Добавление минимального элемента в очередь
    Add_to_priority_queue(pq, m, pos);

    cout << "Очередь после добавления минимального элемента на позицию " << pos << ":\n";
    print_priority_queue(pq);  // Печать очереди после изменения

    RemoveGreaterThanAverage(pq);
    cout << "Очередь после удаления элементов больше среднего арифметического:\n";
    print_priority_queue(pq);  // Печать очереди после удаления

    MultiplyByMax(pq);
    cout << "Очередь после умножения каждого элемента на максимальный:\n";
    print_priority_queue(pq);  // Печать очереди после умножения

    return 0;
}
