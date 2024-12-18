#pragma once
#include "TRIAD.h"

class DATE : public TRIAD {
public:
    DATE(void);
    DATE(int, int, int);
    ~DATE(void);
    DATE(const DATE&); // Конструктор копирования

    void Show() const override {
        std::cout << "DATE: " << first << "/" << second << "/" << third << std::endl;
    }
    // Методы увеличения полей
    void Increase_day();    // Увеличение дня
    void Increase_month();  // Увеличение месяца
    void Increase_year();   // Увеличение года
    void Add_days(int);   // метод добавления n дней

    friend istream& operator>>(istream& in, DATE& d);
    friend ostream& operator<<(ostream& out, const DATE& d);

};
