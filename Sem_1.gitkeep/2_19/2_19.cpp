#include <iostream>
using namespace std;
int main()
{
	int n;
	int sum = 1;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		if ((i % 3) != 0)
		{
			sum += i;
		}
		else
		{
			sum -= i;
		}
	}
	cout << sum;
}