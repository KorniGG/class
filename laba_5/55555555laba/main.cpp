#include "Object.h"
#include "TRIAD.h"
#include "DATE.h"
#include "Vector.h"
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    Vector v(5); // ������ �� 5 ���������

    TRIAD* triad = new TRIAD(1, 2, 3); // ������ TRIAD
    DATE* date = new DATE(25, 12, 2024); // ������ DATE

    Object* p = triad; // ��������� �� TRIAD
    v.Add(p);          // ��������� � ������

    p = date;          // ��������� �� DATE
    v.Add(p);          // ��������� � ������

    cout << "Vector contents:";
    v.Show(); // ����� ����������� �������

    return 0;
}
