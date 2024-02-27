#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	const int p = 100;
	int n = 10;
	int arr[p];

	for (int i = 0; i < n; i++)
	{
		arr[i] = (1 + rand() % (100 - 10 + 1));
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	int del_numb;
	cin >> del_numb;
	int c = 0;

	for (int i = 0; (i < n) and (c == 0); i++)
	{
		if (arr[i] == del_numb)
		{
			c += 1;
			for (int j = i; j < n - 1; j++)
			{
				arr[j] = arr[j + 1];
			}
			i-=1;
			n-=1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		
		int temp = arr[n - 1];
		for (int j = n - 1; j > 0; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[0] = temp;
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}