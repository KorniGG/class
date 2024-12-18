#pragma once
#include "Object.h"
#include <iostream>
using namespace std;

class Vector {
public:
    Vector(int);  // Конструктор
    ~Vector();    // Деструктор

    void Add(Object*);  // Метод для добавления объектов
    void Show() const;  // Метод для вывода всех объектов вектора

    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& out, const Vector& v);

private:
    Object** beg;  // Указатель на массив указателей на объекты
    int size;      // Размер вектора
    int cur;       // Текущий размер вектора (количество объектов)
};
