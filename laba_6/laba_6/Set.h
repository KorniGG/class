#pragma once
#include <iostream>
#include <set>

class Set {
public:
    Set();
    Set(const Set& other); // ����������� �����������
    ~Set(); // ����������

    // �������� ������������
    Set& operator=(const Set& other);

    // �������� ������� �� �������
    int& operator[](int index);

    // �������� ��������� ������� ���������
    int operator()() const;

    // �������� �������� ��������
    Set operator-(const Set& other) const;

    // ���������� ��������� ���������� ��� ���������
    Set& operator--();

    // �������� ����� � ������
    friend std::ostream& operator<<(std::ostream& out, const Set& set);
    friend std::istream& operator>>(std::istream& in, Set& set);

    // ����� ��� ���������� �������� � ���������
    void add(int element);

    // �������� ��� ������ � ���������� ���������
    class Iterator {
    public:
        Iterator(int* elem = nullptr) : elem(elem) {}

        /*
        bool operator==(const Iterator& other) const { return elem == other.elem; }
        bool operator!=(const Iterator& other) const { return elem != other.elem; }

        Iterator& operator++() { ++elem; return *this; }
        */
        Iterator& operator--() { --elem; return *this; }

        int& operator*() const { return *elem; }

    private:
        int* elem;
    };

    Iterator first() { return Iterator(data); }
    Iterator last() { return Iterator(data + size -1); }

private:
    int size;
    int* data; // ������������ ������ ��� �������� ��������� ���������
};
