#include <iostream>
#include <vector>
using namespace std;

const int INF = 1001001001;
int main() {
	int n; cin >> n;
	vector<vector<char>> a(5, vector<char> (n));
	for(int i = 0; i < 5; i++) for(int j = 0; j < n; j++) cin >> a[i][j];
	vector<vector<int>> dp(n+1, vector<int> (3, INF));
	for(int j = 0; j < 3; j++) dp[0][j] = 0;
	for(int i = 1; i <= n; i++) for(int j = 0; j < 3; j++) {
		for(int k = 0; k < 3; k++) {
			if(k == j) continue;
			char c;
			if(j == 0) c = 'R'; 
			else if(j == 1) c = 'B';
			else if(j == 2) c = 'W';
			int cnt = 0;
			for(int l = 0; l < 5; l++) if(a[l][i-1] != c) cnt++; 
			dp[i][j] = min(dp[i][j], dp[i-1][k] + cnt);
		}
	}
	int ans = INF;
	for(int i = 0; i < 3; i++) {
		ans = min(ans, dp[n][i]);
	}
	cout << ans << endl;
}
