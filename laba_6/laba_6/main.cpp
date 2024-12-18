#include "Set.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "RUS");

    Set a;
    a.add(1);
    a.add(2);
    a.add(3);

    std::cout << "Множество a: " << a << std::endl;

    Set b;
    b.add(3);
    b.add(4);
    b.add(5);

    std::cout << "Множество b: " << b << std::endl;

    // Разность множеств
    Set c = a - b;
    std::cout << "Множество a - b: " << c << std::endl;

    // Доступ по индексу
    std::cout << "Элемент по индексу 1 в множестве a: " << a[1] << std::endl;

    // Размер множества
    std::cout << "Размер множества a: " << a() << std::endl;

    // Инкремент и декремент итератора
    Set::Iterator it = a.last();
    std::cout << "Последний элемент множества а: " << *it << std::endl;
    --it;
    std::cout << "предыдущий элемент: " << *it << std::endl;

    return 0;
}
