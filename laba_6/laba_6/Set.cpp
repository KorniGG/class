#include "Set.h"
#include <iostream>
#include <algorithm>

Set::Set() : size(0), data(nullptr) {}

Set::Set(const Set& other) {
    size = other.size;
    data = new int[size];
    std::copy(other.data, other.data + size, data);
}

Set::~Set() {
    delete[] data;
}

Set& Set::operator=(const Set& other) {
    if (this == &other) return *this;
    delete[] data;
    size = other.size;
    data = new int[size];
    std::copy(other.data, other.data + size, data);
    return *this;
}

int& Set::operator[](int index) {
    if (index < size) return data[index];
    std::cerr << "Error! Index out of range\n";
    exit(1);
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
    if (size > 0) {
        --size;
        int* new_data = new int[size];
        std::copy(data, data + size, new_data);
        delete[] data;
        data = new_data;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Set& set) {
    for (int i = 0; i < set.size; ++i) {
        out << set.data[i] << " ";
    }
    return out;
}

std::istream& operator>>(std::istream& in, Set& set) {
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
