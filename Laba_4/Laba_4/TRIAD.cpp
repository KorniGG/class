#include "TRIAD.h"

// Конструктор без параметров 
TRIAD::TRIAD(void) {
    first = 0;
    second = 0;
    third = 0;
}

// Деструктор 
TRIAD::~TRIAD(void) {}

// Конструктор с параметрами 
TRIAD::TRIAD(int F, int S, int T) {
    first = F;
    second = S;
    third = T;
}

// Конструктор копирования 
TRIAD::TRIAD(const TRIAD& traid) {
    first = traid.first;
    second = traid.second;
    third = traid.third;
}

// Модификаторы
void TRIAD::Set_first(int F) {
    first = F;
}

void TRIAD::Set_second(int S) {
    second = S;
}

void TRIAD::Set_third(int T) {
    third = T;
}

// Перегрузка операции присваивания 
TRIAD& TRIAD::operator=(const TRIAD& t) {
    if (&t == this)
        return *this;
    first = t.first;
    second = t.second;
    third = t.third;
    return *this;
}

// Глобальная функция для ввода 
istream& operator>>(istream& in, TRIAD& t) {
    cout << "\nFirst num:";
    in >> t.first;
    cout << "\nSecond num:";
    in >> t.second;
    cout << "\nThird:";
    in >> t.third;
    return in;
}

// Глобальная функция для вывода
ostream& operator<<(ostream& out, const TRIAD& t) {
    out << "\nFirst num: " << t.first;
    out << "\nSecond num: " << t.second;
    out << "\nThird: " << t.third;
    out << "\n";
    return out;
}

// Увеличение каждого поля по отдельности
void TRIAD::Increase_first() {
    first++;
}

void TRIAD::Increase_second() {
    second++;
}

void TRIAD::Increase_third() {
    third++;
}
