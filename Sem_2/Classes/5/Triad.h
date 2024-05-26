#pragma once
#include "Object.h"

class Triad : public Object {
protected:
    int first;
    int second;
    int third;

public:
    Triad(int f = 0, int s = 0, int t = 0) : first(f), second(s), third(t) {}
    virtual void Show() const override {
        cout << "(" << first << ", " << second << ", " << third << ")" << endl;
    }
    virtual ~Triad() {}

    virtual void setFirst(int f) { first = f; }
    virtual void setSecond(int s) { second = s; }
    virtual void setThird(int t) { third = t; }

    virtual int getFirst() const { return first; }
    virtual int getSecond() const { return second; }
    virtual int getThird() const { return third; }

    virtual bool isEqual(const Triad& other) const = 0; // Чисто виртуальная функция

    friend ostream& operator<<(ostream& out, const Triad& triad) {
        out << "(" << triad.getFirst() << ", " << triad.getSecond() << ", " << triad.getThird() << ")";
        return out;
    }
};

