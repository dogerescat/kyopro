#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ll n, k; cin >> n >> k;
	vector<ll> a(n);
	for(ll i = 0; i < n; i++) cin >> a[i];
	ll ans = 1e18;
	for(ll bit = 1; bit < 1 << n; bit++) {
		ll total = 0;
		vector<ll> b = a;
		ll m = b[0];
		ll cnt = 1;
		for(ll i = 1; i < n; i++) {
			if(bit & 1 << i) {
				if(m >= b[i]) {
					total += m - b[i] + 1;
					b[i] += m - b[i] + 1;
				}
			}
			if(m < b[i]) {
				m = b[i];
				cnt++;
			}
		}
		if(k <= cnt) ans = min(ans, total);
	}
	cout << ans << endl;
}
