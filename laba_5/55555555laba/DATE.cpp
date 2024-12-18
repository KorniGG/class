#include "DATE.h"
#include <iostream>

// Конструктор без параметров
DATE::DATE(void) {
    first = 1;      // День
    second = 1;     // Месяц
    third = 2000;   // Год
}

// Конструктор с параметрами
DATE::DATE(int day, int month, int year) {
    first = day;
    second = month;
    third = year;
}

// Деструктор
DATE::~DATE(void) {}

// Конструктор копирования
DATE::DATE(const DATE& D)
{
    first = D.first;
    second = D.second;
    third = D.third;
}


// Увеличение года
void DATE::Increase_year() {
    Increment_first();
}

// Увеличение месяца
void DATE::Increase_month() {
    Increment_second();
    if (second > 12) {
        second = 1;
        Increase_year();
    }
}

// Переопределение метода увеличения дня
void DATE::Increase_day() {
    Increment_third();
    if (third > 31) {  // Условие для дней, без учета месяцев
        third = 1;
        Increase_month();
    }
}

// Метод добавления n дней
void DATE::Add_days(int n) {
    while (n > 0) {
        Increase_day();
        n--;
    }
}

// Операция ввода
istream& operator>>(istream& in, DATE& d) {
    int y, m, d1;

    cout << "\nВведите год: ";
    while (!(in >> y)) {  // Если ввод не удалось
        in.clear();  // Очистить флаг ошибки
        in.ignore(numeric_limits<streamsize>::max(), '\n');  // Пропустить некорректный ввод
        cout << "Неверный ввод. Введите год: ";
    }

    cout << "Введите месяц: ";
    while (!(in >> m) || m < 1 || m > 12) {  // Проверка месяца
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Неверный месяц. Введите месяц (1-12): ";
    }

    cout << "Введите день: ";
    while (!(in >> d1) || d1 < 1 || d1 > 31) {  // Проверка дня
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Неверный день. Введите день (1-31): ";
    }

    // Если все значения корректны, присваиваем их объекту
    d.first = y;
    d.second = m;
    d.third = d1;

    return in;
}
// Операция вывода
ostream& operator<<(ostream& out, const DATE& d) {
    out << "\nДата: " << d.third << "/" << d.second << "/" << d.first;
    return out;
}
