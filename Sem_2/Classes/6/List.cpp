
#include "List.h"

List::List(int count) {
	n = count;
	head = new node;
	head->key = 0;
	lastnd = head;
	for (int i = 1; i < n; i++) {
		cur = new node;
		cur->key = 0;
		lastnd->next = cur;
		lastnd = cur;
	}
	lastnd->next = NULL;
}

List::~List() {
	lastnd = head;
	while (lastnd != NULL) {
		cur = lastnd->next;
		delete lastnd;
		lastnd = cur;
	}
	n = 0;
}

List& List::operator=(List& l) {
	if (this != &l) {
		if (this != 0) {
			lastnd = head;
			while (lastnd != NULL) {
				cur = lastnd->next;
				delete lastnd;
				lastnd = cur;
			}
			n = 0;
		}
		lastnd = head = new node;
		l.lastnd = l.head->next;
		lastnd->key = l.head->key;
		while (l.lastnd != NULL) {
			lastnd->next = new node;
			lastnd->next->key = l.lastnd->key;
			l.lastnd = l.lastnd->next;
			lastnd = lastnd->next;
		}
		lastnd->next = NULL;
		n = l.n;
	}
	return *this;
}

int& List::operator[](int index) {
	if (index < n) {
		lastnd = head;
		for (int i = 0; i < index; i++) {
			lastnd = lastnd->next;
		}
		return lastnd->key;
	}
	else {
		cout << "";
	}
}

int List::operator () () {
	return n;
}

Iterator List::first() {
	beg.cur = head;
	return beg;
}

Iterator List::last() {
	lastnd = head;
	while (lastnd->next != NULL) {
		lastnd = lastnd->next;
	}
	end.cur = lastnd;
	return end;
}

ostream& operator<<(ostream& out, List& l) {
	if (l.n) {
		l.lastnd = l.head;
		while (l.lastnd != NULL) {
			out << l.lastnd->key << ' ';
			l.lastnd = l.lastnd->next;
		}
	}
	else {
		out << "";
	}
	return out;
}

istream& operator>>(istream& in, List& l) {
	l.lastnd = l.head;
	while (l.lastnd != NULL) {
		in >> l.lastnd->key;
		l.lastnd = l.lastnd->next;
	}
	return in;
}

void List::operator << (int number) {
	if (head == NULL) {
		head = new node;
		head->key = number;
		head->next = NULL;
	}
	else {
		lastnd = head;
		while (lastnd->next != NULL) {
			lastnd = lastnd->next;
		}
		lastnd->next = new node;
		lastnd->next->key = number;
		lastnd = lastnd->next;
		lastnd->next = NULL;
	}
	n += 1;
}
