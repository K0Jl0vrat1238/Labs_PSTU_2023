#include<iostream>
#include "Collaborator.h"
using namespace std;

Collaborator make_payday() {
    string fio;
    string post;
    double zp;

    cout << "Введите ФИО работника\n";
    getline(cin, fio);

    cout << "Введите зарплату работника\n";
    cin >> zp;

    cout << "Введите должность\n";
    getline(cin, post);

    Collaborator p(fio, post, zp);
    return p;
}

void print_collaborator(Collaborator p) {
    p.show();
}

int  main() {
    system("chcp 1251>null");
    Collaborator p1;
    p1.show();
    cout << "\n";

    Collaborator p2("Костылёв s1mple Олегович", "Скамейка запасных", 200000);
    p2.show();
    cout << "\n";
    Collaborator p3(p2);
    p3.show();
    p3.set_fio("Крышковец donk Данил");
    p3.set_post("рифлер");
    p3.set_salary(250000);
    print_collaborator(p3);
    cout << "\n\n";
    p1 = make_payday();
    p1.show();
    cout << "\n";

}
