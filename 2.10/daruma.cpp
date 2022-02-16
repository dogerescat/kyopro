#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int f(vvi &dp, vi &w, int l, int r) {
	if((r-l) <= 1) return 0;	
	if((r-l) == 2) {
		if(abs(w[l]-w[l+1]) <= 1) {
			return 2;
		} else {
			return 0;
		}
	}
	if(dp[l][r] != -1) return dp[l][r];
	if(abs(w[l]-w[r-1]) <= 1 && f(dp, w, l+1, r-1) == r-l-2) dp[l][r] = max(dp[l][r], r-l);
	for(int i = l+1; i < r; i++) {
		dp[l][r] = max(dp[l][r], f(dp, w, l, i) + f(dp, w, i, r));
	}
	return dp[l][r];
}

int main() {
	vi ans;
	while(true) {
		int n; cin >> n;
		if(!n) break;
		vi w(n);
		for(int i = 0; i < n; i++) cin >> w[i];
		vvi dp(n+2, vi (n+2, -1));		
		ans.push_back(f(dp, w, 0, n));
	}
	for(auto i : ans) {
		cout << i << endl;
	}
	return 0;
}
