#include "Tree.h"
#include<iostream>
#include"Dialog.h"

Tree::Tree() {
	beg = nullptr;
	size = 0;
	cur = 0;
}
Tree::Tree(int n) {
	beg = new Object * [n];
	cur = 0;
	size = n;
}
Tree::~Tree(void) {
	if (beg != 0) { delete[] beg; }
	beg = 0;
}
void Tree::Add() {
	Object* p;

	cout << "\n1.Print\n";
	cout << "2.Magazin\n";
	int choise;
	cin >> choise; cout << "\n";

	if (choise == 1) {
		Print* a = new (Print);
		a->Input();
		p = a;
		if (cur < size) {
			beg[cur] = p;
			cur++;
		}
	}
	else if (choise == 2) {
		Magazin* b = new (Magazin);
		b->Input();
		p = b;
		if (cur < size) {
			beg[cur] = p;
			cur++;
		}
	}
	else return;
}
void Tree::Show()
{
	if (cur == 0) {
		cout << "\nEmpty" << endl;
	}
	Object** p = beg;
	for (int i = 0; i < cur; i++) {
		(*p)->Show();
		p++;
	}
}
int Tree::operator()() {
	return cur;
}
void Tree::Del(void) {
	if (cur == 0) {
		return;
	}
	cur--;
}
void Tree::Find(int tmp) {
	Object** p = beg;
	for (int i = 0; i < cur; i++) {
		if (i == tmp - 1) {
			(*p)->Show();
		}
		p++;
	}
}
void Tree::HandleEvent(const TEvent& event) {
	if (event.what == evMessage) {
		Object** p = beg;
		for (int i = 0; i < cur; i++) {
			(*p)->Show();
			++p;
		}
	}
}