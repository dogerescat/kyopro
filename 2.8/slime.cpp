#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const ll INF = 1001001001001001;

ll f(vvl &dp, vvi &flag, vl &b, int l, int r) {
	if(flag[l][r])return dp[l][r];
	flag[l][r] = 1;
	if(l + 1 == r) return dp[l][r] = 0;
	ll res = INF;
	for(int m = l+1; m <= r; m++) {
		res = min(res, f(dp, flag, b, l, m)+f(dp, flag, b, m, r));
	}
	return dp[l][r] = res + (b[r] - b[l]);
}
int main() {
	int n; cin >> n;
	vi a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vl b(n+1);
	for(int i = 1; i <= n; i++) b[i] = a[i-1] + b[i-1];
	vvl dp(n+1, vl(n+1));	
	vvi flag(n+1, vi (n+1));
	ll ans = f(dp, flag, b, 0, n);	
	cout << ans << endl;
}
