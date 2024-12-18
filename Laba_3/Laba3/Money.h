#pragma once

#include <iostream>
using namespace std;

class Money {
    long rubles; // рубли
    int kopecks; // копейки
public:
    Money() { rubles = 0; kopecks = 0; } // конструктор без параметров
    Money(long r, int k) { rubles = r; kopecks = k; } // конструктор с параметрами
    Money(const Money& m) { rubles = m.rubles; kopecks = m.kopecks; } // конструктор копирования
    ~Money() {} // деструктор

    // Методы доступа
    long get_rubles() { return rubles; }
    int get_kopecks() { return kopecks; }
    void set_rubles(long r) { rubles = r; }
    void set_kopecks(int k) { kopecks = k; }

    // Перегруженные операции
    Money& operator=(const Money&); // оператор присваивания
    Money& operator--();            // префиксная форма вычитания копеек
    Money operator--(int);          // постфиксная форма вычитания копеек

    // Операции сравнения
    bool operator==(const Money&) const;
    bool operator!=(const Money&) const;

    // Глобальные функции ввода-вывода
    friend istream& operator>>(istream& in, Money& m);
    friend ostream& operator<<(ostream& out, const Money& m);
};


