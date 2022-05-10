#include <iostream>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

ll f(ll x, ll n) {
	ll res = 1;
	while(n) {
		if(n & 1) res = res * x % MOD;
		x = x * x % MOD;
		n >>= 1;
	}
	return res;
}
ll f2(ll a, ll b) {
	ll x = 1, y = 1;		
	for(ll i = 0; i < b; i++) {
		x = x * (a - i) % MOD;
		y = y * (i + 1) % MOD;
	}
	return x * f(y, MOD-2) % MOD;
}

int main() {
	ll n, a, b; cin >> n >> a >> b;
	ll ans = f(2, n);
	--ans;
	ans = (ans - f2(n, a) + MOD) % MOD;
	ans = (ans - f2(n, b) + MOD) % MOD;
	cout << ans << endl;
}
