#include "List_F.h"
#include "Pair.h"



int main() {
    system("chcp 1251 > null");


    cout << "Исходный ссписок" << endl;
    list<Pair> a = { Pair(6, 2.9), Pair(7, 9), Pair(2, 3.5) };
    Show_list(a);

    cout << "Список после добавления среднего значения в конец" << endl;
    Push_average_value(a);
    Show_list(a);

    double begin, end;


    cout << "Введите диапозон, элементы содержащие ключи внутри которого будут удалены\n";
    cout << "От: ";
    cin >> begin;
    cout << "До: ";
    cin >> end;
    cout << "Список после удаления элементов содержащих ключи в заданном диапазоне\n";
    Delete_range_keys(a, begin, end);
    Show_list(a);

    cout << "Список, после добавления к каждому элементу суммы максимального и минимального элементов\n";
    Plus_sum_Min_Max(a);
    Show_list(a);

    return 0;
}