#pragma once
#include "Triad.h"

class Time : public Triad {
public:
    Time(int h = 0, int m = 0, int s = 0) : Triad(h, m, s) {}
    virtual void Show() const override {
        cout << "Time: " << first << "h " << second << "m " << third << "s" << endl;
    }
    void setHours(int h) { setFirst(h); }
    void setMinutes(int m) { setSecond(m); }
    void setSeconds(int s) { setThird(s); }

    int getHours() const { return getFirst(); }
    int getMinutes() const { return getSecond(); }
    int getSeconds() const { return getThird(); }

    bool isEqual(const Triad& other) const override {
        const Time& o = static_cast<const Time&>(other);
        return getHours() == o.getHours() &&
            getMinutes() == o.getMinutes() &&
            getSeconds() == o.getSeconds();
    }

    // Определение операций сравнения для Time
    bool operator==(const Time& other) const {
        return isEqual(other);
    }

    bool operator!=(const Time& other) const {
        return !isEqual(other);
    }

    bool operator<(const Time& other) const {
        // Сравниваем по общему количеству секунд
        return getTotalSeconds() < other.getTotalSeconds();
    }

    bool operator>(const Time& other) const {
        return getTotalSeconds() > other.getTotalSeconds();
    }

    bool operator<=(const Time& other) const {
        return getTotalSeconds() <= other.getTotalSeconds();
    }

    bool operator>=(const Time& other) const {
        return getTotalSeconds() >= other.getTotalSeconds();
    }

private:
    int getTotalSeconds() const {
        return getHours() * 3600 + getMinutes() * 60 + getSeconds();
    }
};
    

