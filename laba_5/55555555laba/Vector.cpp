#include "Vector.h"

using namespace std;

Vector::Vector(int s) {
    size = s;
    cur = 0;
    beg = new Object * [size];  // Выделяем память для массива указателей
}

Vector::~Vector() {
    for (int i = 0; i < cur; ++i) {
        delete beg[i];  // Удаляем объекты
    }
    delete[] beg;  // Освобождаем массив указателей
}

// Метод добавления объекта
void Vector::Add(Object* obj) {
    if (cur < size) {
        beg[cur++] = obj;  // Добавляем объект в вектор
    }
    else {
        cout << "Vector is full!" << endl;
    }
}

// Метод для вывода всех объектов вектора
void Vector::Show() const {
    for (int i = 0; i < cur; ++i) {
        beg[i]->Show();  // Для каждого объекта вызываем его метод Show
    }
}

// Перегрузка оператора вывода
ostream& operator<<(ostream& out, const Vector& v) {
    for (int i = 0; i < v.cur; ++i) {
        v.beg[i]->Show();  // Для каждого объекта вызываем его метод Show
    }
    return out;
}
