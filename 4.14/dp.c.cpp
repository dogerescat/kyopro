#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;
	vector<vector<int>> A(n, vector<int> (3));
	for(int i = 0; i < n; i++) for(int j = 0; j < 3; j++) cin >> A[i][j];
	vector<vector<int>> dp(n+1, vector<int>(3));
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 3; j++) {
			for(int k = 0; k < 3; k++) {
				if(j == k) continue;
				dp[i][j] = max(dp[i][j], dp[i-1][k] + A[i-1][j]);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < 3; i++) ans = max(ans, dp[n][i]);
	cout << ans << endl;
}
