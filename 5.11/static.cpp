#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll x[101010], v[101010], y[101010], a[101010], b[101010], d[101010];

ll solve(int n, ll c) {
	a[0] = v[0];	
	for(int i = 1; i < n; i++) a[i] = a[i-1] + v[i];
	for(int i = 0; i < n; i++) y[i] = c - x[i];
	b[n-1] = v[n-1];
	for(int i = n-2; i >= 0; i--) b[i] = b[i+1] + v[i];
	d[n-1] = b[n-1] - y[n-1];
	for(int i = n-2; i >= 0; i--) {
		d[i] = b[i] - y[i];
		d[i] = max(d[i], d[i+1]);
	}
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ll sm = 0;
		sm -= x[i];
		sm += a[i];
		ans = max(ans, sm);
		sm -= x[i];
		if(i < n-1) sm += d[i+1];
		ans = max(ans, sm);
	}
	return ans;
}

int main() {
	int n; ll c; cin >> n >> c; 
	for(int i = 0; i < n; i++) cin >> x[i] >> v[i];
	ll ans = 0;
	ans = max(ans, solve(n, c));
	reverse(v, v+n);
	for(int i = 0; i < n; i++) x[i] = c - x[i];
	reverse(x, x+n);
	ans = max(ans, solve(n, c));
	cout << ans << endl;
}
