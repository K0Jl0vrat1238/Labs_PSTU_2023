#include <iostream>
using namespace std;

double sum(double a, double b)
{
	double s = a + b;
	return s;
}
int sum(int a, int b, int az, int bz, int& com_div, int& s)
{
	com_div = az * bz;
	a = a * bz;
	b = b * az;
	s = a + b;
	return (com_div, s);
}
int main() 
{
	double da, db;
	cout << "the first decimal fraction" << "\n";
	cin >> da;
	cout << "the second decimal fraction" << "\n";
	cin >> db;
	double k = sum(da, db);
	cout << "The sum of decimals " << k<<"\n";

	int ia, ib, iaz, ibz, denominator, numerator;
	cout << "Enter the numerator and denominator of the first fraction" << "\n";
	cin >> ia >> iaz;
	cout << "Enter the numerator and denominator of the second fraction" << "\n";
	cin >> ib >> ibz;
	sum(ia, ib, iaz, ibz, denominator, numerator);
	
	cout << "The sum of ordinary fractions " << numerator << " / " << denominator;
	return 0;

}