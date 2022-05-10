#include <iostream>
#include <vector>
using namespace std;
template<class T> void chmin(T& a, T b) {
	if(a > b) a = b;
}

int main() {
	int n; cin >> n;
	vector<int> t(n);
	for(int i = 0; i < n; i++) cin >> t[i];
	int T = 0;
	for(int i = 0; i < n; i++) T += t[i];
	vector<vector<int>> dp(n+1, vector<int> (T+1));
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= T; j++) {
			if(j >= t[i-1]) {
				dp[i][j] |= dp[i-1][j-t[i-1]];
			}
			dp[i][j] |= dp[i-1][j];
		}
	}
	int ans = 1001001001;
	for(int i = 0; i <= T; i++) {
		if(dp[n][i]) chmin(ans, max(i, T-i));	
	} 
	cout << ans << endl;
}
