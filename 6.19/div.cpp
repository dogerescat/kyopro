#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

map<ll, ll> f(ll n) {
	map<ll, ll> m;
	for(ll i = 2; i * i <= n; i++) {
		if(n % i) continue;
		ll e = 0;
		while(n % i == 0) {
			e++;	
			n /= i;
		}
		m[i] = e;
	}
	if(n != 1) m[n] = 1;
	return m;
}

int main() {
	ll n; cin >> n;
	map<ll, ll> m = f(n);
	int ans = 0;
	for(auto &i : m) {
		for(int j = 1; ; j++) {
			if(i.second >= j) {
				ans++;
				i.second -= j;
			} else {
				break;
			}
		}
	}
	cout << ans << endl;
}
