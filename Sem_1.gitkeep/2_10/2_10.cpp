#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    int n;
    int s;
    int max;
    cout << "введиите кол-во чисел: ";
    cin >> n;
    if (n > 0)
    {

        cin >> max;
        for (int i = 1; i < n; i++) 
        {
            cin >> s;
            if (s >= max)
            {
                max = s;
            }
        }
        cout << max;
    }
    else
    {
        cout << "Так не работает";
    }
    


    return 0;
}