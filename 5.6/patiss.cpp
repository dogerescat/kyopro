#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1e18;
int main() {
	int n, m; cin >> n >> m;
	vector<vector<ll>> a(3, vector<ll> (n));	
	for(int i = 0; i < n; i++) cin >> a[0][i] >> a[1][i] >> a[2][i];
	ll ans = -INF;
	for(int bit = 0; bit < 8; bit++) {
		vector<ll> b(n);
		for(int i = 0; i < n; i++) {
			ll el = 0;
			if(bit & 1) el -= a[0][i];
			else el += a[0][i];
			if(bit & 2) el -= a[1][i];
			else el += a[1][i];
			if(bit & 4) el -= a[2][i];
			else el += a[2][i];
			b[i] = el;
		}
		sort(b.rbegin(), b.rend());	
		ll tot = 0;
		for(int i = 0; i < m; i++) tot += b[i];
		ans = max(ans, tot);
	}
	cout << ans << endl;
}
