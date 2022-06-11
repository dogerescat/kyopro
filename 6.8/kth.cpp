#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	int n, q; cin >> n >> q;
	vector<ll> a(n+1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	vector<ll> b(n+1);
	for(int i = 1; i <= n; i++) b[i] = a[i] - a[i-1] - 1;
	for(int i = 0; i < n; i++) b[i+1] += b[i];
	for(int i = 0; i < q; i++) {
		ll k; cin >> k;
		int id = lower_bound(b.begin(), b.end(), k) - b.begin();
		ll ans = 0;
		if(n+1 == id) {
			k -= b[id-1];	
			ans = a[id-1] + k;
		} else {
			ans = a[id] - (b[id] - k + 1);	
		}
		cout << ans << endl;
	}
}
