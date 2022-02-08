#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 1001001001001001001;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;

int main() {
	while(true) {
		int n, m; cin >> n >> m;
		if(!n) break;
		vl C(m), X(n);
		for(int i = 0; i < m; i++) cin >> C[i];
		for(int i = 0; i < n; i++) cin >> X[i];
		vvl dp(n+1, vl (256, INF));
		dp[0][128] = 0;	
		auto clamp = [&](int j, int k) {
			int nj = j + C[k];	
			if(nj < 0) nj = 0;
			else if(nj > 255) nj = 255;
			return nj;
		};
		for(int i = 0; i < n; i++) {
			for(int j = 0; j <= 255; j++) {
				if(dp[i][j] == INF) continue; 
				for(int k = 0; k < m; k++) {
					int nj = clamp(j, k);
					int x = X[i] - nj;
					dp[i+1][nj]	= min(dp[i+1][nj], dp[i][j] + x * x);
				}
			}
		}
		ll ans = INF;
		for(int i = 0; i < 256; i++) ans = min(ans, dp[n][i]);
		cout << ans << endl;
	}
	return 0;
}
