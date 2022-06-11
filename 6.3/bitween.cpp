#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

int main() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	vector<vector<ll>> dp(n+1, vector<ll> (3001));
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 3000; j++) {
			dp[i-1][j+1] += dp[i-1][j];
			dp[i-1][j+1] %= MOD;
		}
		for(int j = a[i-1]; j <= b[i-1]; j++) {
			dp[i][j] += dp[i-1][j];
			dp[i][j] %= MOD;
		}
	}
	for(int i = 1; i <= 3000; i++) dp[n][i] = (dp[n][i] + dp[n][i-1]) % MOD;	
	cout << dp[n][3000] << endl;
}
