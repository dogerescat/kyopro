#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ll n; cin >> n;
	vector<ll> a(n+1);
	for(int i = 1; i <= n; i++) {
		ll j = 0;
		while(i + j <= n) {
			j += i;
			a[j]++;
		}
	}
	ll ans = 0;
	for(ll i = 1; i <= n; i++) {
		ans += i * a[i];
	}
	cout << ans << endl;
}
