#include "Map_f.h"
#include "Pair.h"


int main() {
    system("chcp 1251 > null");

    map <int, Pair> a = { {1, {2, 3.14}}, {2, {4, 5.44}}, {3, {12, 2.15}}, {4, {2, 6.28}} };
    cout << "Исходный словарь" << endl;
    Show_map(a);

    cout << "Словарь после добавления среднего значения в конец" << endl;
    Push_average_value(a);
    Show_map(a);

    double begin, end;
    cout << "Введите диапозон, элементы содержащие ключи, внутри которого будут удалены\n";
    cin >> begin;
    cin >> end;
    Delete_range_keys(a, begin, end);
    cout << "Словаь, после удаления элементов содержащих ключи в заданном диапазоне\n";
    Show_map(a);

    cout << "Словарь, после добавления к каждому элементу суммы максимального и минимального элементов\n";
    Plus_sum_Min_Max(a);
    Show_map(a);

    return 0;
}