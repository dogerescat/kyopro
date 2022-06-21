#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main() {
	int n, k; cin >> n >> k;
	auto sum = [](ll l, ll r) {
		return (l + r) * (r - l + 1) / 2;	
	};
	ll ans = 0;
	for(int i = k; i <= n+1; i++) {
		ll m = sum(0, i-1);	
		ll M = sum(n-i+1, n);
		ans += (M - m + 1);
		ans %= MOD;
	}
	cout << ans << endl;
}
