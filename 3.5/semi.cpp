#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	return !b ? a : gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int main() {
	ll n, m; cin >> n >> m;
	vector<ll> a(n);	
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) a[i] /= 2;
	bool ok = true;
	int t = 0;
	while(a[0] % 2 == 0) {
		a[0] /= 2;
		t++;
	}
	for(int i = 1; i < n; i++) {
		int cnt = 0;
		while(a[i] % 2 == 0) {
			a[i] /= 2;
			cnt++;
		}				
		if(cnt != t) ok = false;
	}
	if(!ok) {
		cout << 0 << endl;
		return 0;
	}
	ll l = 1;
	for(int i = 0; i < n; i++) {
		l = lcm(l, a[i]);
		if(l > m) {
			cout << 0 << endl;
			return 0;
		}
	}
	for(int i = 0; i < t; i++) {
		m /= 2;
	}	
	m /= l;
	ll ans = (m + 1) / 2;
	cout << ans << endl;
}
