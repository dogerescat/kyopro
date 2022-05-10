#include <iostream>
#include <vector>
using namespace std;
const int MOD = 998244353;

int main() {
	int n; cin >> n;	
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	vector<vector<int>> dp(n+1, vector<int> (3001));
	dp[0][0] = 1;
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j < 3000; j++) dp[i][j+1] = (dp[i][j] + dp[i][j+1]) % MOD; 
		if(i != n) for(int j = a[i]; j <= b[i]; j++) {
			dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;	
		}
	}
	cout << dp[n][3000] << endl;
}
