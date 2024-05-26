#pragma once
#include <iostream>

class Triad {
protected:
    int first;
    int second;
    int third;

public:
    Triad();
    Triad(int f, int s, int t);
    Triad(const Triad& other);
    ~Triad();

    int getFirst() const;
    int getSecond() const;
    int getThird() const;

    void setFirst(int f);
    void setSecond(int s);
    void setThird(int t);

    Triad& operator=(const Triad& other);

    friend std::istream& operator>>(std::istream& in, Triad& triad);
    friend std::ostream& operator<<(std::ostream& out, const Triad& triad);

    void changeTriad(int f, int s, int t);
    bool isEqual(const Triad& other) const;
};