#include <iostream>
using namespace std;
int main() 
{
    setlocale(LC_ALL, "RU");

    int n, cnt;
    bool pos = false;
    bool neg = false;

    cout << "Кол-во чисел: ";
    cin >> n;

    for (int i = 1; i <= n; i++) 
    {
;
        cin >> cnt;

        if (neg == false and pos == false) 
        {
            if (cnt > 0) 
            {
                pos = true;
            }
            else if (cnt < 0) 
            {
                neg = true;
            }
        }
    }

    if (pos == true) 
    {
        cout << "Сначало положительное";
    }
    else if (neg == true) 
    {
        cout << "Сначало отрицательное";
    }
    else 
    {
        cout << "Одни нули";
    }
    return 0;
}