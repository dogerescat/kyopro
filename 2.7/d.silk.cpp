#include <iostream>
#include <vector>
using namespace std;
const int INF = 1001001001;
int main() {
	int n, m; cin >> n >> m;
	vector<int> D(n), C(m);
	for(int i = 0; i < n; i++) cin >> D[i];
	for(int i = 0; i < m; i++) cin >> C[i];
	vector<vector<int>> dp(n+1, vector<int>(m+1, INF));
	for(int i = 0; i <= m; i++) dp[0][i] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + D[i] * C[j]);
			if(i <= j)dp[i+1][j+1] = min(dp[i+1][j+1], dp[i+1][j]);
		}
	}
	cout << dp[n][m] << endl;
	// int ans = INF;
	// for(int i = n; i <= m; i++) {
	// 	ans = min(ans, dp[n][i]);	
	// }
	// cout << ans << endl;
}
