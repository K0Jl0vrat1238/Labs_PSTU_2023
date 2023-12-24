#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a, b, c;
	cout << "a:";
	cin >> a;
	cout << "b:";
	cin >> b;
	cout << "c:";
	cin >> c;
	int discriminant = b * b + 4 * a * c;
	if (discriminant > 0)
	{
		int x1 = (-b + sqrt(discriminant)) / (2 * a);
		int x2 = (-b - sqrt(discriminant)) / (2 * a);
		cout << x1 << x2;
	}
	else if (discriminant == 0)
	{
		int x = (-b) / (a * 2);
		cout << x;
	}
	else
	{
		cout << "there is no solution";
	}
	return 0;
}