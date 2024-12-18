#pragma once 
#include "TRIAD.h"

// ����� DATE ����������� �� TRIAD
class DATE : public TRIAD {
public:
    DATE(void); // ����������� ��� ����������
    ~DATE(void); // ���������� 
    DATE(int, int, int); // ����������� � �����������
    DATE(const DATE&); // ����������� �����������

    // ���������
    int Get_year() { return first; }  // ���
    int Get_month() { return second; }  // �����
    int Get_day() { return third; }  // ����

    // ������������
    void Set_year(int);
    void Set_month(int);
    void Set_day(int);
    DATE& operator=(const DATE&); // �������� ������������

    // ������ ���������� �����
    void Increase_day();    // ���������� ���
    void Increase_month();  // ���������� ������
    void Increase_year();   // ���������� ����

    // ����� ���������� ���� �� n ����
    void Add_days(int n);

    // �������� �����/������
    friend istream& operator>>(istream& in, DATE& d);
    friend ostream& operator<<(ostream& out, const DATE& d);

};

