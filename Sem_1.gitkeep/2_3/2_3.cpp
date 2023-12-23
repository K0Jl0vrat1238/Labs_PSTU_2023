#include <iostream>
using namespace std;

int main()
{
	int sum = 0;
	int a;
	cin>> a;
	for (int cnt = 1; cnt<=a; cnt++)
	{
		int pr = 1;
		for (int cnt_2 = cnt; cnt_2 <= (cnt * 2); cnt_2++)
		{
			pr *= cnt_2;

		}
		sum += pr;
	}
	cout << sum;

	return 0
}