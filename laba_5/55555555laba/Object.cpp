#pragma once
#include "Object.h"

class TRIAD : public Object {
protected:
    int first, second, third; // Поля класса

public:
    TRIAD(int f = 0, int s = 0, int t = 0) : first(f), second(s), third(t) {}
    ~TRIAD() override = default;

    void Show() const override {
        std::cout << "TRIAD: " << first << ", " << second << ", " << third << std::endl;
    }
};
