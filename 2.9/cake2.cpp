#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<int> vi;

ll f(vvl &dp, vl &a, int &n, int l, int r, int s) {
	if(dp[l][r] != -1) return dp[l][r];
	if(l == r) {
		if(s) return dp[l][r] = 0;
		else return dp[l][r] = a[l];
	}
	if(s) {
		if(a[l] > a[r]) {
			return dp[l][r] = f(dp, a, n, (l+1)%n, r, 0);
		} else {
			return dp[l][r] = f(dp, a, n, l, (r+n-1)%n, 0);
		}
	}
	return dp[l][r] = max(f(dp, a, n, (l+1)%n, r, 1), f(dp, a, n, l, (r+n-1)%n, 1)+a[r]);
}

int main() {
	int n; cin >> n;
	vl a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	ll ans = 0;
	vvl dp(n+1, vl(n+1, -1));
	for(int i = 0; i < n; i++) {
		ll t = a[i];
		t += f(dp, a, n, (i+1)%n, (i+n-1)%n, 1);
		ans = max(ans, t);
	}
	cout << ans << endl;
}
