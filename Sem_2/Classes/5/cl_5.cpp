#include "Vector.h"
#include "Time.h"
#include "Triad.h"

int main() {
    Vector vector;

    // Создание объектов Triad и Time
    Object* t1 = new Time(1, 2, 3);
    Object* t2 = new Time(12, 30, 45);

    // Добавление объектов в вектор
    vector.Add(t1);
    vector.Add(t2);

    // Вывод содержимого вектора
    cout << vector;

 

    return 0;
}
