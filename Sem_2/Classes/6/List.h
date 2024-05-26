#pragma once

#include<iostream>
#include<string>

using namespace std;

struct node {
	int key;
	node* next = nullptr;
};

class Iterator {
private:
	node* cur;
	friend class List;
public:
	Iterator() {
		cur = nullptr;
	};
	Iterator(node* node) {
		cur = node;
	};
	void operator ++ () {
		cur = cur->next;
	}
	node* operator *() const {
		return cur;
	}
	void operator + (int shift) {
		node* tmp = cur;
		int i = 0;
		while (i < shift && cur != nullptr && cur->next != nullptr) {
			cur = cur->next;
			i++;
		}
		if (i < shift) {
			cout << "\n";
			cur = tmp;
		}
	}
};

class List {
private:
	node* lastnd, * cur, * head;
	int n = 0;
	Iterator beg, end;
public:
	List() {};
	List(int);
	~List();
	List& operator=(List&);
	int& operator[](int);
	int operator () ();
	friend ostream& operator << (ostream&, List&);
	friend istream& operator >> (istream&, List&);
	Iterator first();
	Iterator last();
	void operator << (int);
};