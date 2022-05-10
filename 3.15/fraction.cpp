#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ll n; cin >> n;
	ll ans = 0;
	for(ll i = 1; i <= n;) {
		ll x = n / i;
		ll ni = n / x + 1;
		ans += x * (ni - i);	
		i = ni;
	}
	cout << ans << endl;
}
