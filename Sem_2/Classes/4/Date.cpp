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
    cout << "������� �������� ��� ������ 1: ";
    cin >> t1;
    cout << "������ 1: " << t1 << endl;
    cout << "������ 2: " << t2 << endl;

    t1.changeTriad(4, 5, 6);
    cout << "������ 1 ����� ���������: " << t1 << endl;
    cout << "������ 1 � ������ 2 ";
    if (t1.isEqual(t2)) {
        cout << "t1 � t2 �����." << endl;
    }
    else {
        cout << "t1 � t2 �� �����." << endl;
    }

    Date d(2021, 12, 31);
    printTriad(d);

    return 0;
}

