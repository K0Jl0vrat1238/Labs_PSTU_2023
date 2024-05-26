#include <iostream>
#include "List.h"
#include "Pair.h"

using namespace std;

int main() {
    system("chcp 1251 > null");

    List <int> l;
    l << 2;
    l << 4;
    cout << "List<int>:\n";
    cout << l << '\n';

    List <Pair> p;
    Pair c;
    c.SetFirst(16);
    c.SetSecond(20.8);
    p << c;
    cout << "List<Pair>:\n";
    cout << p << '\n';

    return 0;
}