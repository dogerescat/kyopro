#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> dp(n, vector<int> (n, INF));
	for(int i = 0; i < m; i++) {
		int a, b, t; cin >> a >> b >> t;
		--a, --b;
		dp[a][b] = t;
		dp[b][a] = t;
	}
	for(int i = 0; i < n; i++) dp[i][i] = 0;
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				dp[i][j] = min(dp[i][j], dp[k][i] + dp[k][j]);
			}
		}
	}
	int ans = INF;
	for(int i = 0; i < n; i++) {
		int M = 0;
		for(int j = 0; j < n; j++) {
			M = max(M, dp[i][j]);	
		}
		ans = min(ans, M);
	}
	cout << ans << endl;
}
