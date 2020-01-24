#include <iostream>
#include<cmath>
using namespace std;

unsigned long long int fac(int x) {
	unsigned long long int res = 1;

	while (x > 1) {
		res *= x;
		x--;
	}

	return res;
}

void task2() {
	const double X = 3;
	double e;
	cin >> e;
	long double suma = 0;
	long int n = 0;
	long double  r = 0;
	unsigned long long int up = 0, down = 0;

	while (abs(suma - sin(X)) > e) {
		r = pow(-1, n);
		up = pow(X, 2 * n + 1);
		down = fac(2 * n + 1);
		suma += r * up / down;
		n++;
	}
	cout << fixed;

	cout.precision(8);

	cout << suma << endl;
}


int main()
{
	task2();
}


