#include "Pair.h"
#include "Que_F.h"
#include<iostream>


int main() {
    system("chcp 1251 > null");

    priority_queue <Pair> a;
    for (Pair i : { Pair(4, 2.52), Pair(5, 2.5), Pair(10, 23.5) }) {
        a.push(i);
    }
    cout << "Исходная очередь с приоритетом" << endl;
    Show_priority_queue(a);

    cout << "Очередь с приоритетом после добавления среднего значения в конец" << endl;
    Push_average_value(a);
    Show_priority_queue(a);

    double begin, end;

    cout << "Введите диапозон, элементы содержащие ключи внутри которого будут удалены\n";
    cout << "От: ";
    cin >> begin;
    cout << "До: ";
    cin >> end;
    cout << "Oчередь с приоритетом, после удаления элементов содержащих ключи в заданном диапазоне\n";
    Delete_range_keys(a, begin, end);
    Show_priority_queue(a);

    cout << "Oчередь с приоритетом, после добавления к каждому элементу суммы максимального и минимального элементов\n";
    Plus_sum_Min_Max(a);
    Show_priority_queue(a);

    return 0;
}