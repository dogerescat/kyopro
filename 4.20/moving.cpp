#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 1001001001001001;
int main() {
	int n, k; cin >> n >> k;
	vector<ll> p(n), c(n);
	for(int i = 0; i < n; i++) cin >> p[i];
	for(int i = 0; i < n; i++) --p[i];
	for(int i = 0; i < n; i++) cin >> c[i];
	ll ans = -INF;
	for(int i = 0; i < n; i++) {
		ll total = 0;
		int ni = i;
		vector<ll> a;
		while(1) {
			ni = p[ni];
			total += c[ni];
			a.push_back(c[ni]);
			if(i == ni) break;
		}
		ll t = 0;
		ll T = a.size();
		for(int j = 0; j < T; j++) {
			t += a[j];
			if(j + 1 > k) break;
			ll now = t;
			if(total > 0) {
				ll e = (k - j - 1) / T;
				now += total * e;	
			}
			ans = max(ans, now);
		}
	}		
	cout << ans << endl;
}
