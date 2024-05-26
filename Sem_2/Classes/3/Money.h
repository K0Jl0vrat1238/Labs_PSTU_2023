#pragma once
#include <iostream>
using namespace std;

class Money
{
	long rub;
	int copeck;
public:
	Money() { rub = 0; copeck = 0; };
	Money(long r, int c) { rub = r; copeck = c; };
	Money(const Money& m) { rub = m.rub; copeck = m.copeck; };
	~Money() {};

	int get_rub() const;
	int get_copeck() const;
	void set_rub(long r);
	void set_copeck(int c);

	bool operator== (const Money& m) const;
	bool operator!= (const Money& m) const;

	Money& operator= (const Money&);
	Money& operator++ ();
	Money operator++ (int);
	Money operator+ (const Money&);

	friend istream& operator>>(istream& in, Money& m);
	friend ostream& operator<<(ostream& out, const Money& m);

};

