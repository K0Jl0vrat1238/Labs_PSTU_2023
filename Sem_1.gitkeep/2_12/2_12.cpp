#include <iostream>
#include <cmath>
#include <сlimits>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");
    int n,
    cin >> n;
    int maxnumber;
    int minnumber;
    if (n >= 2)
    {
        for (int i = 1; i <= n; i++)
        {
            int number;
            cin >> number;
            if (number > maxnumber)
            {
                maxnumber = number;
            }
            if (number < minnumber)
            {
                minnumber = number;
            }
        }

        cout << minnumber + maxnumber;
    }

}
