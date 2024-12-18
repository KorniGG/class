#include "Set.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "RUS");

    Set a;
    a.add(1);
    a.add(2);
    a.add(3);

    std::cout << "��������� a: " << a << std::endl;

    Set b;
    b.add(3);
    b.add(4);
    b.add(5);

    std::cout << "��������� b: " << b << std::endl;

    // �������� ��������
    Set c = a - b;
    std::cout << "��������� a - b: " << c << std::endl;

    // ������ �� �������
    std::cout << "������� �� ������� 1 � ��������� a: " << a[1] << std::endl;

    // ������ ���������
    std::cout << "������ ��������� a: " << a() << std::endl;

    // ��������� � ��������� ���������
    Set::Iterator it = a.last();
    std::cout << "��������� ������� ��������� �: " << *it << std::endl;
    --it;
    std::cout << "���������� �������: " << *it << std::endl;

    return 0;
}
