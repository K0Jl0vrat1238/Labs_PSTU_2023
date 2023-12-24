//x - (1 / (3 + sin(3,6x)) = 0
//[0,0.85]

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float a = 0, b = 0.85, c;
	float fA, fB, fC;
	double eps = 0.000001;
	while (b - a > eps)
	{
		c = ((a + b) / 2);
		fA = a - (1 / (3 + sin(3.6 * a)));
		fB = b - (1 / (3 + sin(3.6 * b)));
		fC = c - (1 / (3 + sin(3.6 * c)));
		
		if (fA * fC < 0)
		{
			a = c;
		}
		else if (fB * fC < 0)
		{
			b = c;
		}
		else
		{
			cout << "wrong";
		}
		
	}
	cout << a << endl << b;
	return 0;
}