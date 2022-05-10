#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main() {
	int n; cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	ll ans = 0;
	ll t = 1;
	for(int i = 0; i < 60; i++) {
		ll cnt = 0;
		for(int j = 0; j < n; j++) {
			if(a[j] >> i & 1) cnt++;
		}	
		ll now = cnt * (n - cnt) % MOD;
		for(int j = 0; j < i; j++) now = now * 2 % MOD;
		ans = (ans + now) % MOD;
	}	
	cout << ans << endl;
}
