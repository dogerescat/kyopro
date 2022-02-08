#include <iostream>
#include <vector>
using namespace std;
const int INF = 1001001001;
int main() {
	int n, m; cin >> n >> m;
	vector<int> c(m);
	for(int i = 0; i < m;  i++) cin >> c[i];
	vector<vector<int>> dp(m+1, vector<int> (n+1, INF));
	for(int i = 0; i <= m; i++) dp[i][0] = 0;
	for(int i = 1; i <= m; i++) for(int j = 0; j <= n; j++) {
		if(j >= c[i-1]) dp[i][j] = min(dp[i][j], dp[i][j-c[i-1]] + 1);
		dp[i][j] = min(dp[i][j], dp[i-1][j]);
	}
	cout << dp[m][n] << endl;
}
