#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double PI = acos(-1);
int main() {
	double a, b, x; cin >> a >> b >> x;
	double S = x / a;
	double rad;
	if(S >= a * b / 2) {
		double y = 2 * (a * b - S) / a;
		rad = atan2(y, a);
	} else {
		double c = 2 * S / b;
		rad = atan2(b, c);
	}
	double ans = 360 * rad / (2 * PI);
	cout << fixed << setprecision(10) << ans << endl;
}
