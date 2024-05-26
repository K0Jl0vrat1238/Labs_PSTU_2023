
#pragma once
#include<iostream>
#include"Object.h"
#include"Print.h"
#include"Magazin.h"

class Tree {
protected:
	Object** beg;
	int size;
	int cur;
public:
	Tree();
	Tree(int);
	~Tree();
	void Add();
	void Del();
	void Show();
	void Find(int);
	int operator()();
	void HandleEvent(const TEvent& event);
};
