#include "DATE.h"

// ����������� ��� ���������� 
DATE::DATE(void) : TRIAD(1, 1, 1) {}

// ����������
DATE::~DATE(void) {}

// ����������� � �����������
DATE::DATE(int Y, int M, int D) : TRIAD(Y, M, D) {}

// ����������� �����������
DATE::DATE(const DATE& D) : TRIAD(D.first, D.second, D.third) {}

// ������������
void DATE::Set_year(int y) {
    first = y;
}

void DATE::Set_month(int m) {
    if (m >= 1 && m <= 12)
        second = m;
    else
        throw invalid_argument("����� ������ ���� � ��������� �� 1 �� 12.");
}

void DATE::Set_day(int d) {
    if (d >= 1 && d <= 31)
        third = d;
    else
        throw invalid_argument("���� ������ ���� � ��������� �� 1 �� 31.");
}

// ���������� ����
void DATE::Increase_year() {
    Increase_first();
}

// ���������� ������
void DATE::Increase_month() {
    Increase_second();
    if (second > 12) {
        second = 1;
        Increase_year();
    }
}

// ��������������� ������ ���������� ���
void DATE::Increase_day() {
    Increase_third();
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

// �������� ������������
DATE& DATE::operator=(const DATE& d) {
    if (&d == this)
        return *this;
    TRIAD::operator=(d);
    return *this;
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
