#include<iostream>
#include "Collaborator.h"
Collaborator::Collaborator(string fio,string position, double pay) {
    ln_fn_p = fio;
    post = position;
    salary = pay;
}
Collaborator::Collaborator() {
    ln_fn_p = "";
    post = "";
    salary = 0;
}
Collaborator::Collaborator(const Collaborator& p) {
    ln_fn_p = p.ln_fn_p;
    post = p.post;
    salary = p.salary;
}
Collaborator::~Collaborator() {}

string Collaborator::get_fio() {
    return ln_fn_p;
}

string Collaborator::get_post() {
    return post;
}
double Collaborator::get_salary() {
    return salary;
}

void Collaborator::set_fio(string fio) {
    ln_fn_p = fio;
}

void Collaborator::set_post(string position) {
    post = position;
}
void Collaborator::set_salary(double zp) {
    salary = zp;
}
void Collaborator::show() {
    cout << "\nФИO сотрудника: " << ln_fn_p;
    cout << "\nЗарплата: " << salary;
    cout << "\nпозиция: " << post;
}