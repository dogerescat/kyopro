#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	ll left = -1, right = 2e9;
	auto f = [&](ll x) {
		ll res = 0;
		for(int i = 0; i < n; i++) {
			res += max(0LL, a[i] - x);
		}
		return res;
	};
	while(right - left > 1) {
		int mid = (right + left) / 2;
		if(f(mid) < k) right = mid;
		else left = mid;
	}
	ll ans = 0;
	auto asum = [&](ll l, ll r) {
		return (l + r) * (r - l + 1) / 2;
	};
	for(int i = 0; i < n; i++) {
		if(a[i] <= right) continue;
		ans += asum(right+1, a[i]);
	}
	ans += right * (k - f(right));
	cout << ans << endl;
}
