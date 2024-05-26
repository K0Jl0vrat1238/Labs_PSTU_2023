#pragma once
#include <iostream>

using namespace std;

// Абстрактный базовый класс Object
class Object {
public:
    virtual void Show() const = 0; // Чисто виртуальная функция
    virtual ~Object() {}
};
