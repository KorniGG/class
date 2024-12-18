#pragma once
#include "Money.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ������� ��� �������� ����� � ������ � ���� �������� ������ Money
int make_file(const char* f_name)
{
    fstream stream(f_name, ios::out | ios::trunc); // �������� ����� ��� ������
    if (!stream) return -1; // ������ �������� �����
    int n;
    Money m;
    cout << "������� ���������� ������� (N): ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m; // ���� ������� ������ Money �� ������������ ������
        stream << m << "\n"; // ������ ������� � ����
    }
    stream.close(); // �������� �����
    return n; // ������� ���������� ���������� ��������
}

// ������� ��� ������ ����������� ����� �� �����
int print_file(const char* f_name)
{
    fstream stream(f_name, ios::in); // �������� ����� ��� ������
    if (!stream) return -1; // ������ �������� �����
    Money m;
    int i = 0;
    while (stream >> m) // ������ �������� �� ����� �����
    {
        cout << m << " "; // ����� ������� �� �����
        ++i; // ���������� �������� ��������
    }
    stream.close(); // �������� �����
    return i; // ������� ���������� ��������� ��������
}

// ������� ��� �������� �� ����� ���� ��������, ������� ���������
int del_file(const char* f_name, Money t)
{
    fstream temp("temp", ios::out); // ��������� ���� ��� ������
    fstream stream(f_name, ios::in); // �������� ���� ��� ������
    if (!stream) return -1; // ������ �������� �����
    int i = 0; // ������� ������������ ��������
    Money m;
    while (stream >> m) // ������ �������� �� �����
    {
        if (stream.eof()) break; // ������� ����� �����
        i++;
        // ���� ������ ������ ��� ����� ���������, �������� ��� �� ��������� ����
        if (!(m > t))
        {
            temp << m;
        }
    }
    stream.close();
    temp.close();

    remove(f_name); // �������� ������� �����
    rename("temp", f_name); // �������������� ���������� ����� � ��������

    return i; // ������� ���������� ������������ ��������
}


// ������� ��� ��������� ��������, ������ ���������, � �����
int change_file(const char* f_name, Money& t)
{
    fstream temp("temp", ios::out); // ��������� ���� ��� ������
    fstream stream(f_name, ios::in); // �������� ���� ��� ������
    if (!stream) return -1; // ������ �������� �����
    Money m;
    int i = 0;
    while (stream >> m) // ������ �������� �� �����
    {
        if (stream.eof()) break; // ������� ����� �����
        i++;
        if (m != t)
            temp << m; // ������ ������� ��� ���������
        else
            temp << +m; // ��������� ������� (���������� ���������)
    }
    stream.close();
    temp.close();

    remove(f_name); // �������� ������� �����
    rename("temp", f_name); // �������������� ���������� ����� � ��������
    return i; // ������� ���������� ������������ ��������
}

// ������� ��� ���������� ����� �������� ����� ������ � ������� N
int add_file(const char* f_name, int k)
{
    int N; // ���������� ��� �������� ������ ������
    cout << "������� N: ";
    cin >> N; // ������ ������ ������

    fstream temp("temp", ios::out); // ��������� ���� ��� ������
    fstream stream(f_name, ios::in); // �������� ���� ��� ������
    if (!stream) return -1; // ������ �������� �����

    Money m;
    int i = 0; // ������� ���������� ��������
    int current_index = 0; // ������� ����� ������
    int total_records = 0; // ����� ���������� ������� � �����

    // ���������� ���������� �������� � �����
    while (stream >> m)
    {
        total_records++;
    }

    // ��������, �� ������� �� N �� �������
    if (N > total_records)
    {
        cout << "������: ����� ������ N ������� �� ������� ������� (��������: " << total_records << ").\n";
        return -2; // ���������� ������, ���� N ������ ����� �������
    }

    // �������� � ������ �����
    stream.clear();
    stream.seekg(0, ios::beg);

    // ������ �������� �� ����� � ������ � ��������� ����
    while (stream >> m)
    {
        temp << m; // ������ �������� ������� � ��������� ����
        current_index++;

        // ���� ������� ����� ����� N, �������� ����� �������
        if (current_index == N)
        {
            for (int j = 0; j < k; j++)
            {
                cout << "������� ������ Money ��� ����������: ";
                Money n;
                cin >> n;
                temp << n; // ������ ������ �������
                i++;
            }
        }
        i++;
    }

    stream.close();
    temp.close();

    remove(f_name); // �������� ������� �����
    rename("temp", f_name); // �������������� ���������� ����� � ��������

    return i; // ������� ���������� ���������� ��������
}


