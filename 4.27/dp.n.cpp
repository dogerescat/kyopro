#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 1001001001001001;
vector<vector<int>> flag(401, vector<int>(401));
vector<vector<ll>> dp(401, vector<ll>(401));

ll f(vector<ll> &s, int l, int r) {
	if(flag[l][r]) return dp[l][r];
	flag[l][r] = 1;
	ll res = INF;
	if(l == r) return 0;
	for(int m = l; m < r; m++) {
		res = min(res, f(s, l, m) + f(s, m+1, r));
	}	
	return dp[l][r] = res + s[r] - s[l-1];
}
int main() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<vector<int>> flag(n+1, vector<int> (n+1));
	vector<ll> s(n+1); 
	for(int i = 1; i <= n; i++) s[i] = s[i-1] + a[i-1];
	ll ans = f(s, 1, n);
	cout << ans << endl;
}
