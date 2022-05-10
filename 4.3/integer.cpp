#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

int main() {
	int n, m; cin >> n >> m;
	map<ll, ll> mp;	
	for(int i = 0; i < n; i++) {
		ll a; cin >> a;
		mp[a]++;
	}
	for(int i = 0; i < m; i++) {
		ll b, c; cin >> b >> c;
		mp[c] += b;
	}
	auto ite = mp.rbegin();	
	ll ans = 0;
	while(ite != mp.rend() && n) {
		if(n >= ite->second) {
			ans += ite->first * ite->second;
			n -= ite->second;
		} else {
			ans += ite->first * n;
			n = 0;
		}	
		ite++;
	}
	cout << ans << endl;
}
