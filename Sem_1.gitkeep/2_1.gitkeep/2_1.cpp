#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RU");
    int cnt;
    int sum = 0;
    cout << "Введите число: ";
    cin >> cnt;
    for (int count = 1; count <= cnt; count++)
    {
        
        sum += count;

    }
    cout << sum;
}


