
#include "Print.h"
Print::Print() {
	name = "";
	author = "";
}
Print::Print(string n, string a) {
	name = n;
	author = a;
}
Print::Print(const Print& p) {
	name = p.name;
	author = p.author;
}
Print::~Print() {}
void Print::Set_name(string n) {
	name = n;
}
void Print::Set_author(string a) {
	author = a;
}
string Print::Get_name() {
	return name;
}
string Print::Get_author() {
	return author;
}
Print& Print::operator=(const Print& p) {
	if (&p == this) {
		return *this;
	}
	name = p.name;
	author = p.author;
	return *this;
}
void Print::Show() {
	cout << "\nName: " << name;
	cout << "\nAuthor: " << author << endl;
}
void Print::Input() {
	cout << "\nName: "; cin >> name;
	cout << "\nAuthor: "; cin >> author;
}
void Print::HandleEvent(const TEvent& e) {
	if (e.what == evMessage) {
		switch (e.command) {
		case cmGet:
			cout << ": " << Get_name() << '\n';
			break;
		}
	}
}
