#pragma once
#include <iostream>

using namespace std;

// ����������� ������� ����� Object
class Object {
public:
    virtual void Show() const = 0; // ����� ����������� �������
    virtual ~Object() {}
};
