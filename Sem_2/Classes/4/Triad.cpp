#include "Triad.h"
#include <iostream>
using namespace std;

Triad::Triad() : first(0), second(0), third(0) {}

Triad::Triad(int f, int s, int t) : first(f), second(s), third(t) {}

Triad::Triad(const Triad& other) : first(other.first), second(other.second), third(other.third) {}

Triad::~Triad() {}

int Triad::getFirst() const { return first; }
int Triad::getSecond() const { return second; }
int Triad::getThird() const { return third; }

void Triad::setFirst(int f) { first = f; }
void Triad::setSecond(int s) { second = s; }
void Triad::setThird(int t) { third = t; }

Triad& Triad::operator=(const Triad& other) {
    if (this != &other) {
        first = other.first;
        second = other.second;
        third = other.third;
    }
    return *this;
}

std::istream& operator>>(std::istream& in, Triad& triad) {
    in >> triad.first >> triad.second >> triad.third;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Triad& triad) {
    out << "(" << triad.first << ", " << triad.second << ", " << triad.third << ")";
    return out;
}

void Triad::changeTriad(int f, int s, int t) {
    first = f;
    second = s;
    third = t;
}

bool Triad::isEqual(const Triad& other) const {
    return (first == other.first) && (second == other.second) && (third == other.third);
}