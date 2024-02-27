#include <iostream>
using namespace std;
int main()
{
	const int n = 9, m = 9;
	int a[n][m];
	int c = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((i + j) % 2 == 1)
			{
				a[i][j] = 0; 
			}
			else
			{
				if (c == 10)
				{
					c = 1;
				}
				a[i][j] = c;
				c++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << "\t";

		}
		cout << endl;
	}
}