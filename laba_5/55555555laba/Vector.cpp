#include "Vector.h"

using namespace std;

Vector::Vector(int s) {
    size = s;
    cur = 0;
    beg = new Object * [size];  // �������� ������ ��� ������� ����������
}

Vector::~Vector() {
    for (int i = 0; i < cur; ++i) {
        delete beg[i];  // ������� �������
    }
    delete[] beg;  // ����������� ������ ����������
}

// ����� ���������� �������
void Vector::Add(Object* obj) {
    if (cur < size) {
        beg[cur++] = obj;  // ��������� ������ � ������
    }
    else {
        cout << "Vector is full!" << endl;
    }
}

// ����� ��� ������ ���� �������� �������
void Vector::Show() const {
    for (int i = 0; i < cur; ++i) {
        beg[i]->Show();  // ��� ������� ������� �������� ��� ����� Show
    }
}

// ���������� ��������� ������
ostream& operator<<(ostream& out, const Vector& v) {
    for (int i = 0; i < v.cur; ++i) {
        v.beg[i]->Show();  // ��� ������� ������� �������� ��� ����� Show
    }
    return out;
}
