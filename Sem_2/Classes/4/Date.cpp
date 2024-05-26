#include "Triad.h"
#include "Date.h"
#include <iostream>
using namespace std;

void printTriad(const Triad& triad) {
    cout << "Triad: " << triad << endl;
}

int main() {
    system("chcp 1251>null");
    Triad t1;
    Triad t2(1, 2, 3);
    cout << "Введите значения для триады 1: ";
    cin >> t1;
    cout << "триада 1: " << t1 << endl;
    cout << "триада 2: " << t2 << endl;

    t1.changeTriad(4, 5, 6);
    cout << "триада 1 после изменения: " << t1 << endl;
    cout << "триада 1 и триада 2 ";
    if (t1.isEqual(t2)) {
        cout << "t1 и t2 равны." << endl;
    }
    else {
        cout << "t1 и t2 не равны." << endl;
    }

    Date d(2021, 12, 31);
    printTriad(d);

    return 0;
}

