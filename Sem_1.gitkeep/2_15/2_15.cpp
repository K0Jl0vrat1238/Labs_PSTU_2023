#include <iostream>
using namespace std;
int main()
{
	int n;
	int number_s;
	bool f = true;
	cin >> n>> number_s;
	
	while ( (n > 0) and (f = true))
	{
		int degit_number = n % 10;
		if (degit_number == number_s)
		{
			cout << "the figure is in this number";
			f = false;
		}
		n /= 10;
	}
	return 0;
}

