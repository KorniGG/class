#include <iostream>
#include "TRIAD.h"
#include "DATE.h"

using namespace std;

// ���������� ������� ��� ������ � �������� TRIAD
void f1(TRIAD& c) {
    c.Set_first(1);
    c.Set_second(2);
    c.Set_third(3);

    cout << "������ TRIAD ����� ���������:\n" << c;
}

// �������, ������������ ������ ������ DATE
DATE f2() {
    DATE l(1, 1, 2000); // ������� ������ DATE � ������������� �����
    return l;
}

int main() {
    setlocale(LC_ALL, "Russian");

    // ������ � ������� TRIAD
    TRIAD a;
    cout << "������� �������� ��� ������� TRIAD:\n";
    cin >> a;
    cout << "������ TRIAD ����� �����:\n" << a;

    TRIAD b(10, 20, 30);
    cout << "������ TRIAD � ��������� ����������:\n" << b;

    a = b;
    cout << "������ TRIAD ����� ������������:\n" << a;

    // ������ � ������� DATE
    DATE c;
    cout << "������� �������� ��� ������� DATE (����, �����, ���):\n";
    cin >> c;
    cout << "������ DATE ����� �����:\n" << c;

    c.Add_days(40); // ����������� ���� �� 40 ����
    cout << "\n������ DATE ����� ���������� 40 ����:\n" << c;

    // ������� �����������
    cout << "\n������ � �������� TRIAD ����� ������� f1 (������� �����������):\n";
    f1(c); // �������� ������ DATE, ������� ����������� �� TRIAD

    a = f2(); // ������� � ������� ������ ������ DATE
    cout << "������ TRIAD ����� ������������ ���������� ������� f2:\n" << a;

    return 0;
}
