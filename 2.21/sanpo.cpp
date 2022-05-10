#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

ll f(ll m, ll n) {
	ll res = 1;
	ll x = m;
	while(n) {
		if(n & 1) res = res * x % MOD;
		x = x * x % MOD;	
		n >>= 1;
	}
	return res%MOD;
}

int main() {
	int n, q; cin >> n >> q;
	vector<ll> a(n), c(q), b(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < q; i++) cin >> c[i];
	for(int i = 1; i < n; i++) {
		b[i] = f(a[i-1], a[i]);
	}	
	for(int i = 1; i < n; i++) {
		b[i] = (b[i] + b[i-1]) % MOD;
	}	
	ll ans = b[c[0]-1] % MOD;
	for(int i = 1; i < q; i++) {
		ll x = min(c[i-1]-1, c[i]-1);	
		ll y = max(c[i-1]-1, c[i]-1);
		ans = (ans + b[y] - b[x] + MOD * 2) % MOD;
		ans %= MOD;
	}
	ans = (ans + b[c[q-1]-1]) % MOD;
	cout << ans << endl;
}
