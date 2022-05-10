#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
template<class T> void chmax(T &a, T b) {
	if(a < b) a = b;
}

int main() {
	int n, W; cin >> n >> W;
	vector<int> w(n), v(n);
	for(int i = 0; i < n; i++) cin >> w[i] >> v[i];
	vector<vector<ll>> dp(n+1, vector<ll> (W+1));
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= W; j++) {
			if(j >= w[i-1]) {
				chmax(dp[i][j], dp[i-1][j-w[i-1]] + v[i-1]);				
			}
			chmax(dp[i][j], dp[i-1][j]);
		}
	}
	ll ans = 0;
	for(int i = 0; i <= W; i++) chmax(ans, dp[n][i]);
	cout << ans << endl;	
}
