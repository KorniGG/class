#include "DATE.h"
#include <iostream>

// ����������� ��� ����������
DATE::DATE(void) {
    first = 1;      // ����
    second = 1;     // �����
    third = 2000;   // ���
}

// ����������� � �����������
DATE::DATE(int day, int month, int year) {
    first = day;
    second = month;
    third = year;
}

// ����������
DATE::~DATE(void) {}

// ����������� �����������
DATE::DATE(const DATE& D)
{
    first = D.first;
    second = D.second;
    third = D.third;
}


// ���������� ����
void DATE::Increase_year() {
    Increment_first();
}

// ���������� ������
void DATE::Increase_month() {
    Increment_second();
    if (second > 12) {
        second = 1;
        Increase_year();
    }
}

// ��������������� ������ ���������� ���
void DATE::Increase_day() {
    Increment_third();
    if (third > 31) {  // ������� ��� ����, ��� ����� �������
        third = 1;
        Increase_month();
    }
}

// ����� ���������� n ����
void DATE::Add_days(int n) {
    while (n > 0) {
        Increase_day();
        n--;
    }
}

// �������� �����
istream& operator>>(istream& in, DATE& d) {
    int y, m, d1;

    cout << "\n������� ���: ";
    while (!(in >> y)) {  // ���� ���� �� �������
        in.clear();  // �������� ���� ������
        in.ignore(numeric_limits<streamsize>::max(), '\n');  // ���������� ������������ ����
        cout << "�������� ����. ������� ���: ";
    }

    cout << "������� �����: ";
    while (!(in >> m) || m < 1 || m > 12) {  // �������� ������
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "�������� �����. ������� ����� (1-12): ";
    }

    cout << "������� ����: ";
    while (!(in >> d1) || d1 < 1 || d1 > 31) {  // �������� ���
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "�������� ����. ������� ���� (1-31): ";
    }

    // ���� ��� �������� ���������, ����������� �� �������
    d.first = y;
    d.second = m;
    d.third = d1;

    return in;
}
// �������� ������
ostream& operator<<(ostream& out, const DATE& d) {
    out << "\n����: " << d.third << "/" << d.second << "/" << d.first;
    return out;
}
