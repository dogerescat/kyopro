#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;
	double ans = 0;
	for(int i = 1; i < n; i++) {
		ans += (double)1 / i;
	}	
	ans *= (double)n;
	printf("%.10f\n", ans);
}
