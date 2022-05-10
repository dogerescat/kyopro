#include <iostream>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

ll p(ll n, ll m) {
	ll res = 1;
	ll x = n;
	while(m) {
		if(m & 1) res = res * x % MOD;
		x = x * x % MOD;
		m >>= 1;
	}
	return res;
}

ll f(ll a, ll b) {
	ll x = 1, y = 1;
	for(ll i = 0; i < b; i++) {
		x = x * (i + 1) % MOD;
		y = y * (a - i) % MOD;
	}
	return y * p(x, MOD-2) % MOD;
}
int main() {
	ll n, k; cin >> n >> k;	
	ll ans = f(n+k-1, k);
	cout << ans << endl;
}
