#pragma once
#include<iostream>
#include "Object.h"


using namespace std;

class Print :
	public Object {
protected:
	string name;
	string author;
public:
	Print();
	Print(string, string);
	Print(const Print&);
	~Print();
	void Set_name(string);
	void Set_author(string);
	string Get_name();
	string Get_author();
	Print& operator=(const Print&);
	void Show();
	void Input();
	void HandleEvent(const TEvent& e);
};