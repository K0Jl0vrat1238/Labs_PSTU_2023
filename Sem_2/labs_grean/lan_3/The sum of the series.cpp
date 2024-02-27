#include <iostream>
using namespace std;
float SUM_S(float n, float x)
{
	float sum = 0;
	while (n >= 0)
	{
		sum += pow(x, (4 * n + 1)) / (4 * n + 1);
		n--;
	}
	return sum;
}
int main()
{
	float n, x;
	cin >> n >> x;
	float s = SUM_S(n, x);
	cout << s;
	return 0; 
}