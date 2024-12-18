#pragma once 
#include <string> 
#include <iostream>
using namespace std;

class TRIAD {
    // ����������� ��� ���������� 
public:
    TRIAD(void);

public:
    virtual ~TRIAD(void); // ����������
    TRIAD(int, int, int); // ����������� � ����������� 
    TRIAD(const TRIAD&); // ����������� �����������

    // ���������
    int Get_first() { return first; }
    int Get_second() { return second; }
    int Get_third() { return third; }

    // ������������
    void Set_first(int);
    void Set_second(int);
    void Set_third(int);
    TRIAD& operator=(const TRIAD&); // ���������� �������� ������������

    // ������ ���������� �������� �����
    void Increase_first();
    void Increase_second();
    void Increase_third();

    // ���������� ���������-������� �����-������
    friend istream& operator>>(istream& in, TRIAD& c);
    friend ostream& operator<<(ostream& out, const TRIAD& c);

protected:
    int first;
    int second;
    int third;
};

