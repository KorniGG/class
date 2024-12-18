#pragma once  
#include <ctime>  
#include <iostream> 
using namespace std;  

template<class T>  
class Set
{
private:
    T size;  
    T* array;  
public:
    Set(T size);
    ~Set() { delete[] array; size = 0; }
    int& operator [](int index);

    // Операция получения размера множества
    int operator()() const;

    // Операция разности множеств (множество текущего объекта минус множество другого объекта)
    Set operator-(const Set& other) const;

    // Перегрузка оператора вывода в поток (для вывода содержимого массива).
    friend ostream& operator<<(ostream& out, const Set<T>& a);

    // Перегрузка оператора ввода из потока (для ввода значений в массив).
    friend istream& operator>>(istream& in, Set<T>& a);

    // Метод для отображения содержимого массива (вывод на экран).
    virtual void show()
    {
        cout << "Массив: ";  // Сообщение перед выводом массива.
        for (int i = 0; i < size; i++)  // Перебор всех элементов массива.
        {
            cout << " " << array[i];  // Вывод каждого элемента массива.
        }
        cout << endl;  // Перенос строки после вывода массива.
    }
};

// Конструктор класса, который инициализирует массив случайными числами от 1 до 100.
template<class T>
Set<T>::Set(T size)
{
    this->size = size;  // Установка размера массива.
    array = new T[size];  // Выделение памяти для массива.
    for (int i = 0; i < size; i++)  // Инициализация массива случайными числами.
    {
        array[i] = rand() % 100 + 1;  // Генерация случайного числа от 1 до 100.
    }
}

// Перегрузка оператора индексации для доступа к элементам массива по индексу.
template<class T>
int& Set<T>::operator [](int index)
{
    if (index >= 0 && index < size)  // Проверка на допустимый индекс.
    {
        return array[index];  // Возвращаем элемент по индексу.
    }
    else
    {
        cout << endl << "Ошибка" << endl;  // Если индекс неверный, выводим ошибку.
    }
}

// Операция получения размера множества
template<class T>
int Set<T>::operator()() const
{
    return size;  // Возвращаем размер множества
}

// Операция разности множеств (возвращает множество, содержащее элементы, которые есть в текущем, но отсутствуют в другом множестве)
template<class T>
Set<T> Set<T>::operator-(const Set& other) const
{
    // Создаем новое множество для хранения результата
    Set<T> result(this->size);

    int resultSize = 0;  // Переменная для отслеживания размера нового множества
    for (int i = 0; i < size; i++)  // Перебор элементов текущего множества
    {
        bool found = false;
        for (int j = 0; j < other.size; j++)  // Перебор элементов другого множества
        {
            if (array[i] == other.array[j])  // Если элемент найден в другом множестве
            {
                found = true;
                break;
            }
        }
        if (!found)  // Если элемент не найден в другом множестве, добавляем его в результат
        {
            result.array[resultSize++] = array[i];
        }
    }
    result.size = resultSize;  // Устанавливаем новый размер множества
    return result;  // Возвращаем результат разности множеств
}

// Перегрузка оператора вывода для печати элементов массива.
template<class T>
ostream& operator<<(ostream& out, const Set<T>& a)
{
    for (int i = 0; i < a.size; ++i)  // Перебор всех элементов массива.
    {
        out << a.array[i] << " ";  // Вывод каждого элемента.
    }
    return out;  // Возвращаем поток для возможности цепочки операций вывода.
}

// Перегрузка оператора ввода для чтения элементов массива.
template<class T>
istream& operator>>(istream& in, Set<T>& a)
{
    for (int i = 0; i < a.size; ++i)  // Перебор всех элементов массива.
    {
        in >> a.array[i];  // Чтение каждого элемента массива с потока ввода.
    }
    return in;  // Возвращаем поток для возможности цепочки операций ввода.
}
