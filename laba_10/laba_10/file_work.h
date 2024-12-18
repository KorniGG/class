#pragma once
#include "Money.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Функция для создания файла и записи в него объектов класса Money
int make_file(const char* f_name)
{
    fstream stream(f_name, ios::out | ios::trunc); // Открытие файла для записи
    if (!stream) return -1; // Ошибка открытия файла
    int n;
    Money m;
    cout << "Введите количество записей (N): ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m; // Ввод объекта класса Money из стандартного потока
        stream << m << "\n"; // Запись объекта в файл
    }
    stream.close(); // Закрытие файла
    return n; // Возврат количества записанных объектов
}

// Функция для вывода содержимого файла на экран
int print_file(const char* f_name)
{
    fstream stream(f_name, ios::in); // Открытие файла для чтения
    if (!stream) return -1; // Ошибка открытия файла
    Money m;
    int i = 0;
    while (stream >> m) // Чтение объектов до конца файла
    {
        cout << m << " "; // Вывод объекта на экран
        ++i; // Увеличение счётчика объектов
    }
    stream.close(); // Закрытие файла
    return i; // Возврат количества считанных объектов
}

// Функция для удаления из файла всех объектов, БОЛЬШИХ заданного
int del_file(const char* f_name, Money t)
{
    fstream temp("temp", ios::out); // Временный файл для записи
    fstream stream(f_name, ios::in); // Исходный файл для чтения
    if (!stream) return -1; // Ошибка открытия файла
    int i = 0; // Счётчик обработанных объектов
    Money m;
    while (stream >> m) // Чтение объектов из файла
    {
        if (stream.eof()) break; // Признак конца файла
        i++;
        // Если объект МЕНЬШЕ или РАВЕН заданному, записать его во временный файл
        if (!(m > t))
        {
            temp << m;
        }
    }
    stream.close();
    temp.close();

    remove(f_name); // Удаление старого файла
    rename("temp", f_name); // Переименование временного файла в исходный

    return i; // Возврат количества обработанных объектов
}


// Функция для изменения объектов, равных заданному, в файле
int change_file(const char* f_name, Money& t)
{
    fstream temp("temp", ios::out); // Временный файл для записи
    fstream stream(f_name, ios::in); // Исходный файл для чтения
    if (!stream) return -1; // Ошибка открытия файла
    Money m;
    int i = 0;
    while (stream >> m) // Чтение объектов из файла
    {
        if (stream.eof()) break; // Признак конца файла
        i++;
        if (m != t)
            temp << m; // Запись объекта без изменений
        else
            temp << +m; // Изменение объекта (префиксный инкремент)
    }
    stream.close();
    temp.close();

    remove(f_name); // Удаление старого файла
    rename("temp", f_name); // Переименование временного файла в исходный
    return i; // Возврат количества обработанных объектов
}

// Функция для добавления новых объектов после записи с номером N
int add_file(const char* f_name, int k)
{
    int N; // Переменная для хранения номера записи
    cout << "Введите N: ";
    cin >> N; // Запрос номера записи

    fstream temp("temp", ios::out); // Временный файл для записи
    fstream stream(f_name, ios::in); // Исходный файл для чтения
    if (!stream) return -1; // Ошибка открытия файла

    Money m;
    int i = 0; // Счётчик записанных объектов
    int current_index = 0; // Текущий номер записи
    int total_records = 0; // Общее количество записей в файле

    // Подсчитаем количество объектов в файле
    while (stream >> m)
    {
        total_records++;
    }

    // Проверим, не выходит ли N за пределы
    if (N > total_records)
    {
        cout << "Ошибка: Номер записи N выходит за пределы индекса (максимум: " << total_records << ").\n";
        return -2; // Возвращаем ошибку, если N больше числа записей
    }

    // Вернемся в начало файла
    stream.clear();
    stream.seekg(0, ios::beg);

    // Чтение объектов из файла и запись в временный файл
    while (stream >> m)
    {
        temp << m; // Запись текущего объекта в временный файл
        current_index++;

        // Если текущий номер равен N, добавить новые объекты
        if (current_index == N)
        {
            for (int j = 0; j < k; j++)
            {
                cout << "Введите объект Money для добавления: ";
                Money n;
                cin >> n;
                temp << n; // Запись нового объекта
                i++;
            }
        }
        i++;
    }

    stream.close();
    temp.close();

    remove(f_name); // Удаление старого файла
    rename("temp", f_name); // Переименование временного файла в исходный

    return i; // Возврат количества записанных объектов
}


