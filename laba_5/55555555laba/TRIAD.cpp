#include "TRIAD.h"

TRIAD::TRIAD(void) {
    first = 0;
    second = 0;
    third = 0;
}

TRIAD::TRIAD(int f, int s, int t) {
    first = f;
    second = s;
    third = t;
}

// Деструктор 
TRIAD::~TRIAD(void)
{
    cout << "Вызван деструктор для объекта " << this << endl;
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



void TRIAD::Increment_first() { first++; }
void TRIAD::Increment_second() { second++; }
void TRIAD::Increment_third() { third++; }



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
ostream& operator<<(ostream& out, const TRIAD& t)
{
    out << "\nFirst num: " << t.first;
    out << "\nSecond num: " << t.second;
    out << "\nThird: " << t.third;
    out << "\n";
    return out;
}
