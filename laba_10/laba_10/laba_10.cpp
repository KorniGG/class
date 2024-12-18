#include <iostream>
#include <fstream>
#include <string>
#include "Money.h"
#include "file_work.h"
using namespace std;

void main()
{
	setlocale(0, "Rus");
	Money m, temp;
	int k, c, num, cnt;
	char file_name[30];
	do
	{					// ����
		cout << "\n0. �����";
		cout << "\n1. ������� ����"; // �������� �����
		cout << "\n2. ������� ����"; // ������ �����
		cout << "\n3. ������� ��� ������ ������� ��������� ��������";
		cout << "\n4. ��������� ��� ������ � �������� ��������� �� 1 ��� 50 ���";
		cout << "\n5. �������� K ������� ����� ������ � ������� N\n";
		cin >> c;
        switch (c)
        {
        case 1:
            cout << "�������� �����? ";
            cin >> file_name; // ������ ��� �����
            k = make_file(file_name); // ����� ������� ��� ������ � ����
            if (k < 0) cout << "�� ������� ������� ����\n"; // ����� ��������� �� ������
            break;
        case 2:
            cout << "�������� �����? ";
            cin >> file_name;
            k = print_file(file_name);
            if (k == 0) cout << "������ ����\n";
            if (k < 0) cout << "�� ������� ��������� ����\n";
            break;
        case 3:
            cout << "�������� �����? ";
            cin >> file_name;
            cout << "������� �����: ";
            cin >> temp;
            k = del_file(file_name, temp);
            if (k < 0) cout << "�� ������� ��������� ����\n";
            break;
        case 4:
            cout << "�������� �����? ";
            cin >> file_name;
            cout << "������� �����: ";
            cin >> temp;
            k = change_file(file_name, temp);
            if (k < 0) cout << "�� ������� ��������� ����";
            break;
        case 5:
            cout << "�������� �����? ";
            cin >> file_name;
            cout << "������� k: ";
            cin >> k;
            int a = add_file(file_name, k);
            if (a < 0) cout << "�� ������� ��������� ����";
        }


	} while (c != 0);
}