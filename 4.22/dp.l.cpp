#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 1e18;
int main() {
	int n; cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<vector<ll>> dp(n+1, vector<ll> (n+1));
	vector<vector<bool>> flag(n+1, vector<bool>(n+1));
	auto f = [&](auto f, int l, int r) {
		if(l > r) return 0LL;
		if(flag[l][r]) return dp[l][r];
		flag[l][r] = true;
		int diff = n - (r - l + 1);
		ll res = 0;
		if(diff % 2 == 0) {
			res = -INF;
			res = max(res, f(f, l+1, r) + a[l]);
			res = max(res, f(f, l, r-1) + a[r]);
		} else {
			res = INF;
			res = min(res, f(f, l+1, r) - a[l]);
			res = min(res, f(f, l, r-1) - a[r]);
		}
		return dp[l][r] = res;
	};
	cout << f(f, 0, n-1) << endl;
}
