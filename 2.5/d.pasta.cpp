#include <iostream>
#include <vector>
using namespace std;
const int MOD = 10000;

int main() {
	int n, k; cin >> n >> k;
	vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (4, vector<int> (4)));
	vector<int> v(n+1, -1);
	for(int i = 0; i < k; i++) {
		int a, b; cin >> a >> b;
		--b;
		v[a] = b;
	}
	dp[0][3][3] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 4; j++) for(int k = 0; k < 4; k++) for(int l = 0; l < 3; l++) {
			if(j == l && k == l) continue;
			if(v[i] >= 0 && v[i] != l) continue;
			dp[i][k][l] = (dp[i][k][l] + dp[i-1][j][k]) % MOD;
		}
	}
	int ans = 0;
	for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) {
		ans = (ans + dp[n][i][j]) % MOD;
	}
	cout << ans << endl;
}
