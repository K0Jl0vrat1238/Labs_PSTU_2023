#include <iostream>
using namespace std;

int main()
{	
	setlocale(LC_ALL, "RU");
	float a, b;
	cin >> a >> b;
	if (b == 0)
	{
		cout << "не можем разделить";
	}
	else
	{

		cout << a / b;
	}

}