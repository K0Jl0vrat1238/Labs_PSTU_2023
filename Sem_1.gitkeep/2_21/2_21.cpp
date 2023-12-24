#include <iostream>
using namespace std;
int main()
{
	int n, t;
	bool f = true;

	cin >> t;

	while (t != 0)
	{
		cin >> n;
		if ((n != 0) and (t > n))
		{
			f = false;
		}
		t = n;
	}
	if (f)
	{
		cout << "Ascending order";
	}
	else
	{
		cout << "not ascending";
	}
	return 0;
}
