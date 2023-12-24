﻿﻿//f = x - (1 / (3 + sin(3,6x)) 
//f' = 1 + ((18*cos(3,6x)) / (5 * (3+sin(3,6x))**2)
// f'' = (-3240 * sin(3,6x) - 1944 - 324 * sin(3,6x)*(cos(3,6x)**2)) / (25 * ((3+sin(3,6x))**4)
// r = 1.38 
// λ = -0.05
//[0;0.85];
#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	double  x = 0, lamda = -0.05, xperv = 0, eps = 0.000001;
	while (abs(x - xperv) > eps)
	{
		xperv = x;
		x = xperv + lamda*(xperv - (1 / (3 + sin(3.6 * xperv))));

	}
	cout << x;
}