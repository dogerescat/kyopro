#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
template <class T> void chmin(T &a, T b) {
	if(a > b) a = b;
}

const int INF = 1001001001;

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> dp(n+1, vector<int> (n+1, INF));
	for(int i = 0; i <= n; i++) dp[i][i] = 0;
	for(int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		dp[a][b] = c;
	}
	ll ans = 0;	
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) {
			chmin(dp[i][j], dp[i][k] + dp[k][j]);			
			if(dp[i][j] != INF) ans += dp[i][j];
		}
	}
	cout << ans << endl;	
}
