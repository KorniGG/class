#pragma once
#include "Object.h"
#include <iostream>
using namespace std;

class Vector {
public:
    Vector(int);  // �����������
    ~Vector();    // ����������

    void Add(Object*);  // ����� ��� ���������� ��������
    void Show() const;  // ����� ��� ������ ���� �������� �������

    // ���������� ��������� ������
    friend ostream& operator<<(ostream& out, const Vector& v);

private:
    Object** beg;  // ��������� �� ������ ���������� �� �������
    int size;      // ������ �������
    int cur;       // ������� ������ ������� (���������� ��������)
};
