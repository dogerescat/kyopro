#include <iostream>
#include <vector>
using namespace std;
const int MOD = 998244353;

int main() {
	int n, m, k; cin >> n >> m >> k;
	vector<vector<int>> dp(n+1, vector<int>(n*m+1));
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++) for(int j = 0; j <= i*m; j++) {
		for(int l = 1; l <= m; l++) {
			if(j >= l) dp[i][j] = (dp[i][j] + dp[i-1][j-l]) % MOD;	
		}				
	}
	int ans = 0;
	for(int i = 0; i <= k; i++) {
		ans = (ans + dp[n][i]) % MOD;
	}
	cout << ans << endl;
}
