#include <iostream>
#include <cmath>
#include <complex.h>
using namespace std;
using C = complex<double>;

C inC() {
	double a, b; cin >> a >> b;
	return C(a, b);
}

int main() {
	int n; cin >> n;
	C s = inC();		
	C t = inC();
	C o = (s + t) / 2.0;
	double PI = acos(-1);
	double red = 2 * PI / n;
	C r = C(cos(red), sin(red));
	C ans = o + (s - o) * r;
	printf("%.10f %.10f\n", ans.real(), ans.imag());
}
