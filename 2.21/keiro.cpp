#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MOD = 1000000007;
int p(ll n, ll m) {
	ll res = 1;	
	ll x = n;
	while(m) {
		if(m & 1) res = res * x % MOD;
		x = x * x % MOD;
		m >>= 1;
	}
	return res;
}
ll f(ll h, ll w) {
	ll x = 1, y = 1;
	for(ll i = 0; i < h; i++) {
		x = x * (i+1) % MOD;
		y = y * (h + w - i) % MOD;
	}
	return y * p(x, MOD-2) % MOD;
}
int main() {
	ll w, h; cin >> w >> h;
	ll ans = f(h-1, w-1);	
	cout << ans << endl;
}
