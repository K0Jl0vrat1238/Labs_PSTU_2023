#include<iostream>
using namespace std;

class Сoordinate {
public:
    double x, y;

    void init(double f, double s) {
        x = f;
        y = s;
    }

    double distance() {
        return sqrt(x * x + y * y);
    }

    void show() {
        cout << "Координата X: " << x << ", Координата Y: " << y << endl;
    }
};

Сoordinate make_coordinate(double f, double s) {
	Сoordinate t;
	t.init(f, s);
	return t;
}

int main() {
	system("chcp 1251>null");
	double x_cor, y_cor;
	cout << "X коордитната:";
	cin >> x_cor;
	cout << "Y коордитната:";
	cin >> y_cor;
	Сoordinate t = make_coordinate(x_cor, y_cor);
	t.show();
	double result = t.distance();
	cout << result;

}
