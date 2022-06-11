#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int INF = 1e9;
template<class T> void chmin(T& a, T b) {
	if(a > b) a = b;
}
int main() {
	int n, m; cin >> n >> m;
	vector<vector<ll>> dp(n, vector<ll> (n, INF));
	for(int i = 0; i < n; i++) dp[i][i] = 0;
	for(int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		--a, --b;
		dp[a][b] = c;	
	}
	ll ans = 0;
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				chmin(dp[i][j], dp[i][k] + dp[k][j]);
				if(dp[i][j] != INF) ans += dp[i][j];
			}
		}
	}	
	cout << ans << endl;
}
