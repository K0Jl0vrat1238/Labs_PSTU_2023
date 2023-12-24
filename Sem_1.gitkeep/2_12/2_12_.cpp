#include<iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");

    int cnt, n, max, min;

    cout << "Введите количество чисел:";
    cin >> cnt;

    if(cnt != 0)
    {
        cin >> n;
        max = min = n;

        for (int i = 0; i < cnt-1; i++)
        {
            cin >> n;

            if (n > max)
            {
                max = n;
            }
            if (n < min)
            {
                min = n;
            }
        }

        cout << "Макс + Мин = " << max + min;

    }
    return 0;
}