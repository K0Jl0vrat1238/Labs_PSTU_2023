#include <iostream>
#include "list.h"

using namespace std;

int main() {
    system("chcp 1251 > NULL");

    List a(5);
    cout << "Введите 5 элементов:\n";
    cin >> a;
    cout << "Список a:\n";
    cout << a << '\n';
    cout << "меняем 3 элемент\n";
    a[2] = 100;
    cout << "Список a:\n";
    cout << a << '\n';

    List b(10);
    cout << "Список b:\n";
    cout << b << '\n';
    cout << "Умножение элементов списков";
    cout << " a[2] *  b[3] = " << a[2] * b[3] << endl;
    a = b;
    cout << "a = b\n";
    cout << "Размер списка а = " << a() << endl;
    cout << "Список a:\n";
    cout << a << '\n';


    cout << "Выведем список b с помощью итератора:\n";
    for (Iterator i = b.first(); *i != NULL; ++i) {
        cout << (*i)->key << ' ';
    }
    cout << '\n';
    cout << "Добавим 3 элемента в список b\n";
    b << 14;
    b << 22;
    b << 13;
    cout << "Список b:\n";
    cout << b << '\n';
    cout << "Проверим +\n";
    cout << "Cтавим итератор на первый элемент b\n";
    Iterator i = b.first();
    cout << "Смещаем на 11 элементов\n";
    i + 11;
    cout << "Текущий элемент: " << (*i)->key << '\n';

    return 0;
}
