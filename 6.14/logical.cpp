#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main() {
	int n; cin >> n;
	vector<string> s(n);
	for(int i = 0; i < n; i++) cin >> s[i];
	vector<vector<ll>> dp(n+1, vector<ll> (2));
	dp[0][0] = 1;	
	dp[0][1] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= 1; j++) for(int x = 0; x <= 1; x++) {
			int nj = j;
			if(s[i-1] == "AND") nj &= x;
			else nj |= x;
			dp[i][nj] += dp[i-1][j];
		}	
	}
	cout << dp[n][1] << endl;
}
