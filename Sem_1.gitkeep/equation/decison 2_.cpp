﻿//f = x - (1 / (3 + sin(3,6x)) 
//f' = 1 + ((18*cos(3,6x)) / (5 * (3+sin(3,6x))**2)
// f'' = (-3240 * sin(3,6x) - 1944 - 324 * sin(3,6x)*(cos(3,6x)**2)) / (25 * ((3+sin(3,6x))**4)
////[0;0.85];
#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	double x = 0, xperv = 0;
	double eps = 0.000001;
	while (abs(x - xperv) > eps)
	{
		xperv = x;
		x = xperv - (xperv - (1 / (3 + sin(3.6 * xperv)))) / (1 + ((18 * cos(3.6 * xperv)) / (5 * pow((3 + sin(3.6 * xperv)), 2))));
	}
	cout << x;

}