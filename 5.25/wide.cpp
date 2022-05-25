#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ll n, a, b; cin >> n >> a >> b;
	vector<ll> h(n);
	for(int i = 0; i < n; i++) cin >> h[i];
	auto check = [&](ll t) {
		ll tot = 0;	
		for(int i = 0; i < n; i++) {
			ll H = (h[i] - b * t) + a - b - 1;
			if(H <= 0) continue;
			tot += H / (a - b);
		}
		return tot <= t;
	};
	ll left = 0, right = 1001001001;
	while(right - left > 1) {
		ll mid = (right + left) / 2;
		if(check(mid)) right = mid;
		else left = mid;
	}
	cout << right << endl;
}
