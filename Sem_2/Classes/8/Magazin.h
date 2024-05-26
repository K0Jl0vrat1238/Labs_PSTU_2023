#pragma once
#include "Print.h"
class Magazin :
    public Print {
protected:
    int page_count;
public:
    Magazin();
    Magazin(int);
    Magazin(const Magazin&);
    ~Magazin();
    void Set_page_count(int);
    int Get_page_count();
    Magazin& operator=(const Magazin&);
    void Show();
    void Input();
};