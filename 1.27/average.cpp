#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> x(n);
	vector<int> y(n);
	for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
	vector<int> a(n);
	iota(a.begin(), a.end(), 0);
	double t = 1;
	for(int i = 1; i <= n; i++) t *= i;
	long double total = 0;
	do {
		for(int i = 1; i < n; i++) {
			long double X = (x[a[i]] - x[a[i-1]]) * (x[a[i]] - x[a[i-1]]);
			long double Y = (y[a[i]] - y[a[i-1]]) * (y[a[i]] - y[a[i-1]]);
			total += sqrt(X + Y);
		}
	} while(next_permutation(a.begin(), a.end()));
	long double ans = total / t;
	cout << fixed << setprecision(10) << ans << endl;

}
