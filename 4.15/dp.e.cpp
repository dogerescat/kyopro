#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
template<class T> void chmin(T &a, T b) {
	if(a > b) a = b;
}
ll const INF = 1001001001001001;
int main() {
	int n, W; cin >> n >> W;
	vector<vector<ll>> dp(n+1, vector<ll> (100001, INF));
	vector<int> w(n), v(n);
	for(int i = 0; i < n; i++) cin >> w[i] >> v[i];
	for(int i = 0; i <= n; i++) dp[i][0] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= 100000; j++) {
			if(j >= v[i-1]) {
				chmin(dp[i][j], dp[i-1][j-v[i-1]] + w[i-1]);
			}	
			chmin(dp[i][j], dp[i-1][j]);
		}
	}
	ll ans = 0;
	for(int i = 0; i <= 100000; i++) {
		if(W >= dp[n][i]) ans = i;
	}
	cout << ans << endl;
}
