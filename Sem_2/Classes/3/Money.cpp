#include "Money.h"
#include <iostream>
using namespace std;

// Геттеры
int Money::get_rub() const { return rub; }
int Money::get_copeck() const { return copeck; }

// Сеттеры
void Money::set_rub(long r) { rub = r; }
void Money::set_copeck(int c) { copeck = c; }

// Оператор присваивания
Money& Money::operator= (const Money& m) {
    if (this != &m) {
        rub = m.rub;
        copeck = m.copeck;
    }
    return *this;
}

// Префиксный инкремент
Money& Money::operator++ () {
    ++copeck;
    if (copeck >= 100) {
        ++rub;
        copeck -= 100;
    }
    return *this;
}

// Постфиксный инкремент
Money Money::operator++ (int) {
    Money temp = *this;
    ++(*this);
    return temp;
}

// Оператор сложения
Money Money::operator+ (const Money& m) {
    Money result = *this;
    result.copeck += m.copeck;
    result.rub += m.rub + result.copeck / 100;
    result.copeck %= 100;
    return result;
}

// Операторы сравнения
bool Money::operator== (const Money& m) const {
    return (rub == m.rub) && (copeck == m.copeck);
}

bool Money::operator!= (const Money& m) const {
    return !(*this == m);
}

// Дружественные функции ввода-вывода
istream& operator>>(istream& in, Money& m) {
    in >> m.rub >> m.copeck;
    return in;
}

ostream& operator<<(ostream& out, const Money& m) {
    out << m.rub << " руб. " << m.copeck << " коп.";
    return out;
}