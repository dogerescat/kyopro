#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int> x(n), y(n), r(n);
	for(int i = 0; i < n; i++) cin >> x[i] >> y[i] >> r[i];
	vector<int> X(m), Y(m);	
	for(int i = 0; i < m; i++) cin >> X[i] >> Y[i];
	double ans = 1001001001;
	for(int i = 0; i < n; i++) {
		ans = min(ans, (double)r[i]);	
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int a = (x[i] - X[j]) * (x[i] - X[j]);	
			int b = (y[i] - Y[j]) * (y[i] - Y[j]);
			double t = sqrt(a+b);
			ans = min(ans, t-r[i]);
		}
	}
	for(int i = 0; i < m; i++) for(int j = i+1; j < m; j++) {
		int a = (X[i] - X[j]) * (X[i] - X[j]);	
		int b = (Y[i] - Y[j]) * (Y[i] - Y[j]);
		double t = sqrt(a+b);
		ans = min(ans, t/2.0);
	}
	cout << fixed << setprecision(10) << ans << endl;
}
