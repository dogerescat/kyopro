#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ll n, k; cin >> n >> k;
	ll ans = 0;
	for(ll b = 1; b <= n; b++) {
		ll p = n / b;
		ll r = n % b;
		ans += p * max(0LL, b - k);
		ans += max(0LL, r - k + 1);
	}
	if(!k) ans -= n;
	cout << ans << endl;
}
