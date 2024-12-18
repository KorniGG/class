#include "Set.h"
#include <iostream>
#include <algorithm>
using namespace std;

Set::Set() : size(0), data(nullptr) {}

Set::Set(int size)
{
    if (size > MAX_SIZE) throw 1;
    if (size <= 0) throw 1;
    this->size = size;
    data = new int[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = rand() % 100 + 1;
    }
}

Set::Set(const Set& other) {
    if (other.size > MAX_SIZE) throw 1; // если размер больше максимального, то генерируется исключение
    size = other.size;
    data = new int[size];
    copy(other.data, other.data + size, data);
}

Set::~Set() {
    delete[] data;
}

Set& Set::operator=(const Set& other) {
    if (this == &other) return *this;
    delete[] data;
    size = other.size;
    data = new int[size];
    copy(other.data, other.data + size, data);
    return *this;
}

int& Set::operator[](int index) {
    if (index < 0) throw 2; // если индекс отрицательный, генерируется исключение
    if (index >= size) throw 2; // если индекс выходит за пределы массива, генерируется исключение
    if (index >= 0 && index < size) return data[index];
    else
    {
        cout << endl << "Error! Index out of range\n";
    }
}

int Set::operator()() const {
    return size;
}

Set Set::operator-(const Set& other) const {
    Set result;
    for (int i = 0; i < size; ++i) {
        bool found = false;
        for (int j = 0; j < other.size; ++j) {
            if (data[i] == other.data[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result.add(data[i]);
        }
    }
    return result;
}

Set& Set::operator--() {
    if (size == 0) throw 5;  // Если множество пусто, выбрасываем исключение

    Set temp(size - 1);  // Создаём временное множество с размером на 1 меньше
    int j = 0;  // Индекс для временного массива

    // Копируем все элементы, кроме первого
    for (int i = 1; i < size; i++) {
        temp.data[j++] = data[i];
    }

    // Удаляем старое множество
    delete[] data;

    // Уменьшаем размер множества
    size--;
    // Присваиваем новый массив
    data = temp.data;

    // Очищаем временное множество, так как его память теперь используется в текущем объекте
    temp.data = nullptr;

    return *this;
}


/*
Set& Set::operator--() {

    if (size == 0) {
        throw std::underflow_error("Set is empty");
    }
    removeElement(size - 1);
    return *this;
}
*/


ostream& operator<<(ostream& out, const Set& set) {
    if (set.size == 0) {  // Проверка на пустоту множества
        out << "Set is empty.";  // Вывод сообщения о пустоте множества
    }
    else {
        for (int i = 0; i < set.size; ++i) {
            out << set.data[i] << " ";  // Вывод элементов множества
        }
    }
    return out;
}


istream& operator>>(istream& in, Set& set) {
    for (int i = 0; i < set.size; ++i) {
        in >> set.data[i];
    }
    return in;
}

void Set::add(int element) {
    int* new_data = new int[size + 1];
    std::copy(data, data + size, new_data);
    new_data[size] = element;
    delete[] data;
    data = new_data;
    ++size;
}

// Метод удаления элемента из множества
/*
void Set::removeElement(int index) {
    int* newData = new int[size - 1];
    std::copy(data, data + index, newData);
    std::copy(data + index + 1, data + size, newData + index);
    delete[] data;
    data = newData;
    --size;
}
*/