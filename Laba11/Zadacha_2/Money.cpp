#include "Money.h"

// ����������� �� ���������
Money::Money(void)
{
    rubles = 0; // ������������� ������ �����
    kop = 0;    // ������������� ������ �����
}
Money::Money(float value)
{
    rubles = static_cast<long>(value);       // ����� ����� � �����
    kop = static_cast<int>((value - rubles) * 100); // ������� ����� � �������
}

// ����������� � �����������
Money::Money(long r, int k)
{
    rubles = r; // ������������� ������ �������� ���������
    kop = k;    // ������������� ������ �������� ���������
}

// ����������� �����������
Money::Money(const Money& t)
{
    rubles = t.rubles; // ����������� ������ �� ������� �������
    kop = t.kop;       // ����������� ������ �� ������� �������
}

// ���������� ��������� ������������
Money& Money::operator=(const Money& t)
{
    rubles = t.rubles; // ����������� ����� �� ������� �������
    kop = t.kop;       // ����������� ������� �� ������� �������
    return *this;      // ���������� ������ �� ������� ������
}

// ���������� ��������� ������ (��� ������ ������� � �����)
ostream& operator<<(ostream& out, const Money& t)
{
    out << t.rubles << "," << t.kop; // ����� � ������� "�����,�������"
    return out;                      // ���������� �����
}

// ���������� ��������� ����� (��� ����� ������� �� ������)
istream& operator>>(istream& in, Money& t)
{
    cout << "������� �����: "; in >> t.rubles; // ���� ������
    cout << "������� �������: "; in >> t.kop; // ���� ������
    return in;                                // ���������� �����
}

// ���������� ��������� != (�����������)
bool Money::operator!=(const Money& t)
{
    // ���������� true, ���� ����� ��� ������� ����������
    return !(rubles == t.rubles && kop == t.kop);
}

// ���������� ��������� == (���������)
bool Money::operator==(const Money& t)
{
    // ���������� true, ���� ����� � ������� �����
    return rubles == t.rubles && kop == t.kop;
}

// ���������� ��������� < (������)
bool Money::operator<(const Money& t)
{
    if (rubles < t.rubles) return true;      // ��������� ������
    else if (rubles == t.rubles && kop < t.kop) return true; // ��������� ������
    return false; // ���� �� ���� �� ������� �� ���������
}

// ���������� ��������� > (������)
bool Money::operator>(const Money& t)
{
    if (rubles > t.rubles) return true;      // ��������� ������
    else if (rubles == t.rubles && kop > t.kop) return true; // ��������� ������
    return false; // ���� �� ���� �� ������� �� ���������
}

// ���������� ��������� * (���������)
Money Money::operator*(const Money& t)
{
    Money tmp;

    // ��������� ��� ������� � �������, �� ������������� �� ��� ������� �����
    float value1 = rubles + kop / 100.0f;  // ����������� ������ �������� � ����� ��� �����
    float value2 = t.rubles + t.kop / 100.0f;  // ����������� ������ �������� � ����� ��� �����

    // ����������� �� ��� ������� �����
    float result_value = value1 * value2;

    // ����������� ��������� ������� � ����� � �������
    tmp.rubles = static_cast<long>(result_value);  // ����� ����� - �����
    tmp.kop = static_cast<int>((result_value - tmp.rubles) * 100);  // ������� - �������

    return tmp;  // ���������� ���������
}

Money Money::operator+(const Money& t)
{
    long total_kop = rubles * 100 + kop + t.rubles * 100 + t.kop;
    Money tmp;
    tmp.rubles = total_kop / 100;         // ����������� ������� � �����
    tmp.kop = total_kop % 100;            // ���������� �������
    return tmp;
}




Money Money::operator/(int val)
{
    Money tmp; // ��������� ������ ��� ����������
    long total_kop = rubles * 100 + kop; // ����������� ����� � �������
    total_kop /= val;                    // ����� �� ���������� �����

    tmp.rubles = total_kop / 100;        // ������������ ������� � �����
    tmp.kop = total_kop % 100;           // ������������ ������� � �������

    return tmp; // ���������� ��������� �� ��������
}
Money Money::operator/(float val) {
    if (val == 0.0f) {
        throw runtime_error("������� �� ����!");
    }

    Money tmp;
    long total_kop = rubles * 100 + kop; // ����������� ����� � �������
    float result = total_kop / val;     // ����� �� float

    tmp.rubles = static_cast<long>(result) / 100; // ����������� ������� � �����
    tmp.kop = static_cast<int>(result) % 100;    // ���������� �������
    return tmp;
}


Money::operator float() const
{
    return rubles + kop / 100.0f;
}