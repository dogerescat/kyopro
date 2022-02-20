#include <iostream>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

ll f(ll m, ll n) {
	ll x = m;
	ll res = 1;
	while(n) {
		if(n & 1) res = res * x % MOD;	
		x = x * x % MOD;
		n >>= 1;
	}
	return res;
}
int main() {
	ll m, n; cin >> m >> n;	
	ll ans = f(m, n);
	cout << ans << endl;
}
