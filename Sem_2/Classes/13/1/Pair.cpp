#include "Pair.h"

Pair::Pair() {
	first = 0;
	second = 0.0;
}
Pair::Pair(int f, double s) {
	first = f;
	second = s;
}
Pair::Pair(const Pair& p) {
	first = p.first;
	second = p.second;
}
Pair::~Pair() {}
void Pair::set_first(int f) {
	first = f;
}
void Pair::set_second(double s) {
	second = s;
}
int Pair::get_first() const {
	return first;
}
double Pair::get_second() const {
	return second;
}
Pair& Pair::operator+(const Pair& p) {
	first += p.first;
	second += p.second;
	return *this;
}
ostream& operator<<(ostream& out, const Pair& p) {
	return (out << p.first << " : " << p.second);
}
istream& operator>>(istream& in, Pair& p) {
	in >> p.first;
	in >> p.second;
	return in;
}

bool operator < (const Pair& pair1, const Pair& pair) {
	return (pair1.get_first() + pair1.get_second() < pair.get_first() + pair.get_second());
}