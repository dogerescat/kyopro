#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	int h, w; cin >> h >> w;
	vector<vector<char>> a(h+2, vector<char>(w+2, '#'));
	for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++) cin >> a[i][j];
	vector<vector<ll>> dp(h+2, vector<ll>(w+2));
	dp[1][1] = 1;
	for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++) {
		if(a[i][j] == '#') continue;
		if(a[i+1][j] == '.') dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;
		if(a[i][j+1] == '.') dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % MOD;
	}
	cout << dp[h][w] << endl;
}
