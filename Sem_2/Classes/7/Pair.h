#pragma once
#include <iostream>

using namespace std;

class Pair {
private:
	int first;
	double second;
public:
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);
	Pair(int, double);
	Pair();
	Pair(const Pair&);
	~Pair();
	Pair& operator=(const Pair&);
	Pair operator-(const Pair&);
	Pair& operator+(int);
	Pair& operator+(double);
	Pair& operator++();
	Pair operator++(int);
	int GetFirst() const;
	double GetSecond() const;
	void SetFirst(int m_first);
	void SetSecond(double m_second);
};