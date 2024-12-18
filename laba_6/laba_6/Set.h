#pragma once
#include <iostream>
#include <set>

class Set {
public:
    Set();
    Set(const Set& other); // Конструктор копирования
    ~Set(); // Деструктор

    // Операция присваивания
    Set& operator=(const Set& other);

    // Операция доступа по индексу
    int& operator[](int index);

    // Операция получения размера множества
    int operator()() const;

    // Операция разности множеств
    Set operator-(const Set& other) const;

    // Перегрузка оператора инкремента для итератора
    Set& operator--();

    // Операции ввода и вывода
    friend std::ostream& operator<<(std::ostream& out, const Set& set);
    friend std::istream& operator>>(std::istream& in, Set& set);

    // Метод для добавления элемента в множество
    void add(int element);

    // Итератор для работы с элементами множества
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
    int* data; // Динамический массив для хранения элементов множества
};
