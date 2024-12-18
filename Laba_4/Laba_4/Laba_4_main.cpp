#include <iostream>
#include "TRIAD.h"
#include "DATE.h"

using namespace std;

// Глобальная функция для работы с объектом TRIAD
void f1(TRIAD& c) {
    c.Set_first(1);
    c.Set_second(2);
    c.Set_third(3);

    cout << "Объект TRIAD после изменения:\n" << c;
}

// Функция, возвращающая объект класса DATE
DATE f2() {
    DATE l(1, 1, 2000); // Создаем объект DATE с фиксированной датой
    return l;
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Работа с классом TRIAD
    TRIAD a;
    cout << "Введите значения для объекта TRIAD:\n";
    cin >> a;
    cout << "Объект TRIAD после ввода:\n" << a;

    TRIAD b(10, 20, 30);
    cout << "Объект TRIAD с заданными значениями:\n" << b;

    a = b;
    cout << "Объект TRIAD после присваивания:\n" << a;

    // Работа с классом DATE
    DATE c;
    cout << "Введите значения для объекта DATE (день, месяц, год):\n";
    cin >> c;
    cout << "Объект DATE после ввода:\n" << c;

    c.Add_days(40); // Увеличиваем дату на 40 дней
    cout << "\nОбъект DATE после добавления 40 дней:\n" << c;

    // Принцип подстановки
    cout << "\nРабота с объектом TRIAD через функцию f1 (принцип подстановки):\n";
    f1(c); // Передаем объект DATE, который наследуется от TRIAD

    a = f2(); // Создаем в функции объект класса DATE
    cout << "Объект TRIAD после присваивания результата функции f2:\n" << a;

    return 0;
}
