#pragma once 
#include "TRIAD.h"

// Класс DATE наследуется от TRIAD
class DATE : public TRIAD {
public:
    DATE(void); // Конструктор без параметров
    ~DATE(void); // Деструктор 
    DATE(int, int, int); // Конструктор с параметрами
    DATE(const DATE&); // Конструктор копирования

    // Селекторы
    int Get_year() { return first; }  // Год
    int Get_month() { return second; }  // Месяц
    int Get_day() { return third; }  // День

    // Модификаторы
    void Set_year(int);
    void Set_month(int);
    void Set_day(int);
    DATE& operator=(const DATE&); // Операция присваивания

    // Методы увеличения полей
    void Increase_day();    // Увеличение дня
    void Increase_month();  // Увеличение месяца
    void Increase_year();   // Увеличение года

    // Метод увеличения даты на n дней
    void Add_days(int n);

    // Операции ввода/вывода
    friend istream& operator>>(istream& in, DATE& d);
    friend ostream& operator<<(ostream& out, const DATE& d);

};

