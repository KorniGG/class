#include <iostream>
#include < stdlib.h >
#include "fraction.h" // ���������� ������������ ����
using namespace std;

Fraction make_fraction(double F, int S)
{
    Fraction t; // ������� ��������� ����������
    t.Init(F, S); // ���������������� ���� ���������� t � ������� ���������� �������
    return t; // ������� �������� ���������� t
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    // ���������� ���������� A � B
    cout << "  \n�������� ���������� �������:";
    Fraction A;
    Fraction B;

    A.Init(3.0, 4.0); // ������������� ���������� A
    B.Read(); // ������ �������� ��� ���������� B
    cout << "\n������������� ��������� ���������:";
    A.Show(); // ����� �������� ���������� A
    cout << "\n���������, ��������� �������:";
    B.Show(); // ����� �������� ���������� B

    //���������� ����������
    cout << " \nHipotenuza pri katetah: " << A.first << "," << A.second << "=" << A.Hipotenuza() << endl;
    cout << "Hipotenuza pri katetah: " << B.first << "," << B.second << "=" << B.Hipotenuza() << endl;

    cout << "  \n ������������ ��������� ������ ��� ����������: \n";
    // ������������ ��������� ������ ��� X
    Fraction* X = new Fraction;
    X->Init(9.0, 12.0); // �������������
    X->Show(); // ����� ��������
    cout << "Hipotenuza pri katetah: " << X->first << "," << X->second << "=" << X->Hipotenuza() << endl;

    cout << "  \n �������� ������� ����������� ������������ 3: \n";
    // �������
    Fraction mas[3]; // ����������� �������
    for (int i = 0; i < 3; i++)
        mas[i].Read(); // ������ �������� �����
    for (int i = 0; i < 3; i++)
        mas[i].Show(); // ����� �������� �����
    for (int i = 0; i < 3; i++)
    {
        cout << "mas[" << i << "].Hipotenuza pri katetah: " << mas[i].first << "," << mas[i].second << "=" << mas[i].Hipotenuza() << endl;
    }

    cout << "  \n �������� ������������� ������� ����������� ������������ 3: \n";
    // ������������ �������
    Fraction* p_mas = new Fraction[3]; // ��������� ������
    for (int i = 0; i < 3; i++)
        mas[i].Read(); // ������ �������� �����
    for (int i = 0; i < 3; i++)
        mas[i].Show(); // ����� �������� �����
    for (int i = 0; i < 3; i++)
    {
        cout << "mas[" << i << "].Hipotenuza pri katetah: " << mas[i].first << "," << mas[i].second << "=" << mas[i].Hipotenuza() << endl;
        
    }
    
    // ����� ������� make_fraction()
    cout << "  \n �������� ���������� � ������� �������: \n";

    cout << "\n";
    double y;
    int z;
    cout << "first?";
    cin >> y;
    if (cin.fail()) {
        cout << "ERROR!!!! ";
        abort();
    }

    cout << "second?";
    cin >> z;
    if (cin.fail()) {
        cout << "ERROR!!!! ";
        abort();
    }

    
    // ���������� F ����������� � ������� ������� make_fraction()
    Fraction F = make_fraction(y, z);
    F.Show();
    cout << "Hipotenuza pri katetah: " << F.first << "," << F.second << "=" << F.Hipotenuza() << endl;

    // ������������ ������������ ������
    delete X;
    delete[] p_mas;
    
    return 0;
}
