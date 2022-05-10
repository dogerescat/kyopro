#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main() {
	string s; cin >> s;
	int n = s.size();
	vector<vector<ll>> dp(n+1, vector<ll>(13));
	dp[0][0] = 1;
	for(int i = 0; i < n; i++) {
		int c;
		if(s[i] == '?') c = -1;
		else c = s[i] - '0';
		for(int j = 0; j < 10; j++) {
			if(c != -1 && c != j) continue;
			for(int k = 0; k < 13; k++) {
				dp[i+1][(k * 10 + j) % 13] += dp[i][k];
			}
		}
		for(int j = 0; j < 13; j++) dp[i+1][j] %= MOD;
	}
	cout << dp[n][5] << endl;
}
