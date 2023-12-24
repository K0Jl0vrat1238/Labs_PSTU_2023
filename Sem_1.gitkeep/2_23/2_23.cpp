#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float n, b, m;
	int cnt = 1;
	cin >> n;
	m = sin(n + 1 / n);

	for (int i = 2; i <= n; i++)
	{
		b = sin(n + 1 / n);
		if (b > m)
		{
			m = b;
			cnt = 1;
		}
		else if (b == m)
		{
			cnt++;

		}

	}
	cout << m << endl << cnt;
	return 0;
}