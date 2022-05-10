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
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) {
		a[i] /= 2;
	}
	auto f = [](int x) {
		int cnt = 0;
		while(x % 2 == 0) {
			x /= 2;
			cnt++;
		}	
		return cnt;
	};
	int t = f(a[0]);
	for(int i = 0; i < n; i++) {
		if(t != f(a[i])) {
			cout << 0 << endl;
			return 0;
		} 
		a[i] >>= t;
	}
	m >>= t;
	ll L = a[0];
	for(int i = 0; i < n; i++) {
		L = lcm(L, a[i]);			
		if(L > m) {
			cout << 0 << endl;
			return 0;
		}
	}
	m /= L;
	int ans = (m + 1) / 2;
	cout << ans << endl;
}
