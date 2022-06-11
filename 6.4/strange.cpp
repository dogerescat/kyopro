#include <iostream>
#include <vector>
using namespace std;
const int INF = 1001001001;

template<class T> void chmin(T &a, T b) {
	if(a > b) a = b;
}

int main() {
	int n, x, y; cin >> n >> x >> y;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
	vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(x+1, vector<int>(y+1, INF)));
	for(int i = 0; i <= n; i++) dp[i][0][0] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= x; j++) {
			for(int k = 0; k <= y; k++) {
				if(dp[i][j][k] == INF) continue;
				chmin(dp[i+1][min(x, j+a[i])][min(y, k+b[i])], dp[i][j][k] + 1);
				chmin(dp[i+1][j][k], dp[i][j][k]);
			}
		}
	}
	if(dp[n][x][y] != INF) cout << dp[n][x][y] << endl;
	else cout << -1 << endl;
}
