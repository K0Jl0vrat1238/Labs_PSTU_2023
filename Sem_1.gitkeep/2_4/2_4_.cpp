#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int spasec = n / 2;
	int stars = 1;

	for (int i = 0; i < (n + 1) / 2; i++)
	{
		for (int j = 0; j < spasec; j++)
		{
			cout << " ";
		}
		spasec--;
		for (int j = 0; j < stars; j++)
		{
			cout << "*";
		}
		stars += 2;
		cout << endl;
	}
	return 0;
}