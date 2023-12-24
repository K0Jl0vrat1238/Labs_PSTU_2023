#include<iostream>
using namespace std;
int main()
{
	int n, x, r;
	double  sum;
	sum = r = 1;

	cin >> n >> x;

	for (int i = 1; i <=n; i++)
	{
		r *= i;
		sum += (pow(x, i )/ r);
	}
	cout << sum;

	return 0;

}
