#include <iostream>
using namespace std;
int main()
{
    int cnt, b;
    cin >> cnt;
    int sum = 1;
    for (int count = 1; count <= cnt; count += 1)
    {
        cin >> b;
        sum *= b;
    }
    cout << sum;
    return 0;
}