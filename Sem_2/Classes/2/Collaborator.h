#pragma once
#include <iostream>
#include <string>

using namespace std;
class Collaborator
{
    string ln_fn_p;
    string post;
    double salary;

public:
    Collaborator(string, string, double);

    Collaborator();

    Collaborator(const Collaborator&);

    ~Collaborator();

    string get_fio();
    double get_salary();
    string get_post();
    void set_fio(string);
    void set_salary(double);
    void set_post(string);

    void show();


};

