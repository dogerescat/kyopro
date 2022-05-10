#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double a, b; cin >> a >> b;
	double z = sqrt(a * a + b * b);
	double x = a / z;
	double y = b / z;
	cout << fixed << setprecision(10) << x << ' ' << y << endl;
}
