#include <iostream>
using namespace std;

int max(int m, ...)
{
	int* p = &m + 2;
	int mx = *p;
	for (int i = 0;i<m; i++)
	{
		if (mx < *p)
		{
			mx = *p;
		}
		p+=2;
	}
	return mx;
}
double max(double m, ...)
{
	double* p = &m + 2;
	double mx = *p;
	for (int i = 0; i < m; i++)
	{
		if (mx < *p)
		{
			mx = *p;
		}
		p += 2;
	}
	return mx;
}

int main()
{
	cout << max(5, 6, 9, 4, 7, 8)<<"\n";
	cout << max(10.0, 3.432, 3.657, 6.3424, 5.432, 7546.4 , 4353.4, 345.543, 4.435, 34.45, 32.0)<<"\n";
	cout << max(12, 54, 546, 23, 5, 8, 0, 3, -6, 6, 3, 6, 7)<<"\n";
}