#include "Object.h"
#include "TRIAD.h"
#include "DATE.h"
#include "Vector.h"
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    Vector v(5); // Вектор на 5 элементов

    TRIAD* triad = new TRIAD(1, 2, 3); // Объект TRIAD
    DATE* date = new DATE(25, 12, 2024); // Объект DATE

    Object* p = triad; // Указатель на TRIAD
    v.Add(p);          // Добавляем в вектор

    p = date;          // Указатель на DATE
    v.Add(p);          // Добавляем в вектор

    cout << "Vector contents:";
    v.Show(); // Вывод содержимого вектора

    return 0;
}
