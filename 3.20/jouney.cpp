#include <iostream>
using namespace std;

int main() {
	double n; cin >> n;
	double ans = 0;
	for(double i = 1; i < n; i++) {
		ans += (double) 1 / i;	
	}
	ans *= n;
	printf("%.10f\n", ans);
}
