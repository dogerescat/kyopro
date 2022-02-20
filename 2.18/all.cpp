#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 1e18;
int main() {
	int n, m; cin >> n >> m;
	vector<vector<ll>> dp(n, vector<ll> (n, INF));	
	for(int i = 0; i < n; i++) dp[i][i] = 0;
	for(int i = 0; i < m; i++) {
		int a, b; ll d; cin >> a >> b >> d;
		dp[a][b] = d;
	}
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	bool nagative_cycle = false;
	for(int i = 0; i < n; i++) if(dp[i][i] < 0) nagative_cycle = true;
	if(nagative_cycle) {
		cout << "NEGATIVE CYCLE" << endl;
		return 0;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(j) cout << " ";
			if(dp[i][j] < INF/2) cout << dp[i][j];
			else cout << "INF";
		}
		cout << '\n';
	}
}
