#pragma once
#include <iostream>

// ������� ����������� ����� Object
class Object {
public:
    virtual void Show() const = 0; // ����� ����������� ������� ��� �����������
    virtual ~Object() = default;  // ����������� ����������
};
