#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ll n, m; cin >> n >> m;	
	ll ans = 0;
	for(ll i = 1; i * i <= m; i++) {
		if(m % i != 0) continue;
		ll j = m / i;
		if(m >= i * n) ans = max(ans, i);
		if(m >= j * n) ans = max(ans, j);
	}
	cout << ans << endl;
}
