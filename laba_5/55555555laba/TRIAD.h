#pragma once
#include "Object.h"
#include <iostream>
using namespace std;

class TRIAD : public Object {
public:
    TRIAD(void);
    TRIAD(int, int, int);
    virtual ~TRIAD(void);
    TRIAD(const TRIAD&); // Конструктор копирования

    // Селекторы
    int Get_first() { return first; }
    int Get_second() { return second; }
    int Get_third() { return third; }

    void Show() const override {
        std::cout << "TRIAD: " << first << ", " << second << ", " << third << std::endl;
    }
    void Set_first(int);
    void Set_second(int);
    void Set_third(int);

    void Increment_first();
    void Increment_second();
    void Increment_third();

    friend istream& operator>>(istream& in, TRIAD& t);
    friend ostream& operator<<(ostream& out, const TRIAD& t);

protected:
    int first;
    int second;
    int third;
};
