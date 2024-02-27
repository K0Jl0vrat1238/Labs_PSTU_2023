#include <iostream>
using namespace std;


void h_t(int n, int from, int to, int buf) 
{
    setlocale(LC_ALL, "rus");
    if (n != 0) 
    {
        h_t(n - 1, from, buf, to);
        cout << "Переместим диск " << n << " с башни " << from << " на башню " << to << endl;
        h_t(n - 1, buf, to, from);
    }
}

int main() 
{
    setlocale(LC_ALL, "rus");
    int start, finish, buffer, n_disks;

    cout << "Номер первого столбика:" << endl;
    cin >> start;
    cout << "Номер конечного столбика:" << endl;
    cin >> finish;
    cout << "Номер промежуточного столбика:" << endl;
    cin >> buffer;
    cout << "Количество дисков:" << endl;
    cin >> n_disks;

    h_t(n_disks, start, finish, buffer);
    return 0;
}
