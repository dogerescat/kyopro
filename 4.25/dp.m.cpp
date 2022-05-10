#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main() {
	int n, K; cin >> n >> K;	
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<vector<ll>> dp(n+1, vector<ll>(K+1));
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		vector<ll> sum(K+2);
		for(int j = 1; j <= K+1; j++) sum[j] = (sum[j-1] + dp[i-1][j-1]) % MOD;
		for(int j = 0; j <= K; j++) {
			dp[i][j] = (sum[j+1] - sum[max(0, j-a[i-1])] + MOD) % MOD;
		}
	} 
	cout << dp[n][K] << endl;
}
