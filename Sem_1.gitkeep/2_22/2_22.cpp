#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int cnt = 0;
	float n, s, m;

	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		s = sin(n + i / n);

		if (i == 0)
		{
			m = s;
			cnt = i;
		}

		if (s > m)
		{
			m = s;
			cnt = i;
		}

	}

	cout << m << endl << cnt;


}
