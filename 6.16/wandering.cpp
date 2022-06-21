#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	int n; cin >> n;
	vector<ll> a(n);	
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 1; i < n; i++) a[i] += a[i-1];
	vector<ll> x(n);
	x[0] = a[0];
	for(int i = 1; i < n; i++) x[i] = x[i-1] + a[i];
	ll ans = 0;
	ll m = 0;
	for(int i = 0; i < n-1; i++) {
		m = max(m, a[i]);	
		ans = max(ans, x[i] + m);
	}
	ans = max(ans, x[n-1]);
	cout << ans << endl;
}
