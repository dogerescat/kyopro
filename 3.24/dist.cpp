#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> x(n), y(n), a(n), b(n);
	for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
	for(int i = 0; i < n; i++) {
		a[i] = x[i] + y[i];
		b[i] = x[i] - y[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ans = max(a[n-1]-a[0], b[n-1] - b[0]);
	cout << ans << endl;
}
