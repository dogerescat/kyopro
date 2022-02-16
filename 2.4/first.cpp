#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	int n; cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<vector<ll>> dp(n, vector<ll> (31));
	dp[1][a[0]] = 1;
	for(int i = 1; i < n-1; i++) {
		for(int j = 0; j <= 20; j++) {
			if(j + a[i] <= 20) dp[i+1][j + a[i]] += dp[i][j];
			if(j >= a[i]) dp[i+1][j - a[i]] += dp[i][j];
		}
	}
	cout << dp[n-1][a[n-1]] << endl;
}
