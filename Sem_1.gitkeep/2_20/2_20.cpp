#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float n, s, b;
	int i = 1;
	bool f = false;
	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		b = sin(n + i / n);
		b = round(b * 100) / 100;
		cout << b<< endl;

		if (b == s)
		{
			f == true;
		}
	}

	if (f)
	{
		cout << "found";
	}
	else
	{
		cout << "no found";
	}
}