#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<vector<ll>> dp(n, vector<ll> (10));
	dp[0][a[0]] = 1;
	for(int i = 0; i < n-1; i++) {
		for(int j = 0; j < 10; j++) {
			dp[i+1][(j+a[i+1])%10] += dp[i][j];	
			dp[i+1][(j+a[i+1])%10] %= MOD;
			dp[i+1][(j*a[i+1])%10] += dp[i][j];
			dp[i+1][(j*a[i+1])%10] %= MOD;
		}
	}
	for(int i = 0; i < 10; i++) cout << dp[n-1][i] << endl;
}
