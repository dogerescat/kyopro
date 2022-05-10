#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
ll dp[101][4][4][4];
int main() {
	int n; cin >> n;
	dp[0][3][3][3] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 4; j++) {
			for(int k = 0; k < 4; k++) {
				for(int l = 0; l < 4; l++) {
					if(dp[i][j][k][l] == 0) continue;
					for(int a = 0; a < 4; a++) {
						if(a == 2 && j == 1 && k == 0) continue;
						if(a == 1 && j == 2 && k == 0) continue;
						if(a == 2 && j == 0 && k == 1) continue;
						if(a == 2 && j == 1 && l == 0) continue;
						if(a == 2 && k == 1 && l == 0) continue;
						dp[i+1][a][j][k] += dp[i][j][k][l];
						dp[i+1][a][j][k] %= MOD;
					}
				}
			}
		}
	}
	ll ans = 0;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			for(int k = 0; k < 4; k++) {
				ans = (ans + dp[n][i][j][k]) % MOD;
			}
		}
	}
	cout << ans << endl;
}
