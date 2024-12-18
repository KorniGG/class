#pragma once 
#include <string> 
#include <iostream>
using namespace std;

class TRIAD {
    // Конструктор без параметров 
public:
    TRIAD(void);

public:
    virtual ~TRIAD(void); // Деструктор
    TRIAD(int, int, int); // Конструктор с параметрами 
    TRIAD(const TRIAD&); // Конструктор копирования

    // Селекторы
    int Get_first() { return first; }
    int Get_second() { return second; }
    int Get_third() { return third; }

    // Модификаторы
    void Set_first(int);
    void Set_second(int);
    void Set_third(int);
    TRIAD& operator=(const TRIAD&); // Перегрузка операции присваивания

    // Методы увеличения значений полей
    void Increase_first();
    void Increase_second();
    void Increase_third();

    // Глобальные операторы-функции ввода-вывода
    friend istream& operator>>(istream& in, TRIAD& c);
    friend ostream& operator<<(ostream& out, const TRIAD& c);

protected:
    int first;
    int second;
    int third;
};

