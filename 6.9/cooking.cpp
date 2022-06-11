#include <iostream>
#include <vector>
using namespace std;
const int INF = 1001001001;
int main() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	int t = 0;
	for(int i = 0; i < n; i++) t += a[i];
	vector<vector<bool>> dp(n+1, vector<bool> (t+1));
	for(int i = 0; i <= n; i++) dp[i][0] = true;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= t; j++) {
			if(j >= a[i-1] && dp[i-1][j-a[i-1]]) dp[i][j] = true;
			if(dp[i-1][j]) dp[i][j] = true;
		}
	}
	int ans = INF;
	for(int i = 0; i <= t; i++) {
		if(dp[n][i]) ans = min(ans, max(i, t - i));
	}
	cout << ans << endl;
}
