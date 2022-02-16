#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vi;
const ll INF = 1001001001001001001;
ll f(vvi &dp, vi R, vi C, int l, int r) {
	if(dp[l][r] != -1) return dp[l][r]; 	
	if(r-l <= 1) return dp[l][r] = 0;
	ll res = INF;
	for(int m = l+1; m < r; m++) {
		res = min(res, f(dp, R, C, l, m) + f(dp, R, C, m, r) + R[l]*C[m-1]*C[r-1]);		
	}
	return dp[l][r] = res; 
}

int main() {
	int n; cin >> n;
	vi R(n), C(n);
	for(int i = 0; i < n; i++) cin >> R[i] >> C[i];
	vvi dp(n+1, vi (n+1, -1));		
	cout << f(dp, R, C, 0, n) << endl;
}
