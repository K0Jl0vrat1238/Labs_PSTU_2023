
#pragma once
#include <string>
#include <iostream>
using namespace std;

class Error {
private:
	string code[4] = { "Error: can't shift, going off the list!", "Error: imposible get first element empty list!", "Error: imposible get last element empty list!", "Error: index outside the list!" };
	string str;
public:
	Error(int i) {
		str = code[i];
	}
	void What() {
		cout << str << '\n';
	}
};