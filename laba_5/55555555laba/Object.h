#pragma once
#include <iostream>

// Базовый абстрактный класс Object
class Object {
public:
    virtual void Show() const = 0; // Чисто виртуальная функция для отображения
    virtual ~Object() = default;  // Виртуальный деструктор
};
