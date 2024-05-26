#include <iostream>
#include "List.h"
#include "Error.h"

using namespace std;

int main() {
    system("chcp 1251 > NULL");
    try {
        List a(2);
        List b(3);
        a[1] = 10;
        b[2] = 20;
        cout << a[1] * b[2] << endl;
        cout << a << '\n';
        cout << b << '\n';
        cout << b[0] << endl;
        Iterator i = b.first();//Ошибка
        Iterator j = b.last();//Ошибка
        Iterator k = a.last();
        ++k;
        ++k;//Ошибка
        k + 1;//Ошибка
    }
    catch (Error& m_Error) {
        m_Error.What();
    }
    return 0;
}