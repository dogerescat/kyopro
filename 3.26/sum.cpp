#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main() {
	int n, k; cin >> n >> k;
	ll ans = 0;
	auto sum = [&](ll l, ll r) {
		ll res = (l+r) / 2 * (r - l + 1) % MOD;
		return res;
	};
	for(ll i = k; i <= n+1; i++) {
		ll left = sum(0, i-1);
		ll right = sum(n-i+1, n);
		ans = (ans + (right - left + 1) + MOD) % MOD;
	}
	cout << ans << endl;
}
