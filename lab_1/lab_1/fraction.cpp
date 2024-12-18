#include "fraction.h"
using namespace std;

// ���������� ������ ��� ������������� ����� ���������

void Fraction::Init(double F, double S) 
{
    first = F;
    second = S;
}


// ���������� ������ ��� ������ �������� ����� ���������
void Fraction::Read()
{
    cout << "\nfirst?";
    cin >> first;
    cout << "\nsecond?";
    cin >> second;
}

// ���������� ������ ��� ������ �������� ����� ���������
void Fraction::Show() const 
{
    cout << "\nfirst=" << first;
    cout << "\nsecond=" << second; 
    cout << "\n";
}


double Fraction::Hipotenuza()
{
    return sqrt(pow(first, 2) + pow(second, 2));

}
