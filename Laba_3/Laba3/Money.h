#pragma once

#include <iostream>
using namespace std;

class Money {
    long rubles; // �����
    int kopecks; // �������
public:
    Money() { rubles = 0; kopecks = 0; } // ����������� ��� ����������
    Money(long r, int k) { rubles = r; kopecks = k; } // ����������� � �����������
    Money(const Money& m) { rubles = m.rubles; kopecks = m.kopecks; } // ����������� �����������
    ~Money() {} // ����������

    // ������ �������
    long get_rubles() { return rubles; }
    int get_kopecks() { return kopecks; }
    void set_rubles(long r) { rubles = r; }
    void set_kopecks(int k) { kopecks = k; }

    // ������������� ��������
    Money& operator=(const Money&); // �������� ������������
    Money& operator--();            // ���������� ����� ��������� ������
    Money operator--(int);          // ����������� ����� ��������� ������

    // �������� ���������
    bool operator==(const Money&) const;
    bool operator!=(const Money&) const;

    // ���������� ������� �����-������
    friend istream& operator>>(istream& in, Money& m);
    friend ostream& operator<<(ostream& out, const Money& m);
};


