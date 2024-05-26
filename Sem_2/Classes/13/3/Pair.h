#pragma once
#include <iostream>

using namespace std;
class Pair {
	int first;
	double second;
public:
	Pair();
	Pair(int, double);
	Pair(const Pair&);
	~Pair();
	void set_first(int);
	void set_second(double);
	int get_first() const;
	double get_second() const;
	Pair& operator+(const Pair&);
	Pair& operator/(int);
	friend ostream& operator<<(ostream& out, const Pair& p);
	friend istream& operator>>(istream& in, Pair& p);
	friend bool operator <=(const Pair&, double s);
	friend bool operator <= (double, const Pair&);
	friend bool operator<(const Pair&, const Pair&);
};
