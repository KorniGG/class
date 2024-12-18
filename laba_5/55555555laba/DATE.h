#pragma once
#include "TRIAD.h"

class DATE : public TRIAD {
public:
    DATE(void);
    DATE(int, int, int);
    ~DATE(void);
    DATE(const DATE&); // ����������� �����������

    void Show() const override {
        std::cout << "DATE: " << first << "/" << second << "/" << third << std::endl;
    }
    // ������ ���������� �����
    void Increase_day();    // ���������� ���
    void Increase_month();  // ���������� ������
    void Increase_year();   // ���������� ����
    void Add_days(int);   // ����� ���������� n ����

    friend istream& operator>>(istream& in, DATE& d);
    friend ostream& operator<<(ostream& out, const DATE& d);

};
