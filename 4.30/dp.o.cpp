#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main() {
	int n; cin >> n;
	vector<vector<int>> a(n, vector<int> (n));
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a[i][j];
	auto count = [](int n) {
		int res = 0;
		while(n) {
			if(n & 1) res++;
			n >>= 1;
		}
		return res;
	};
	vector<vector<ll>> dp(n+1, vector<ll> (1 << n));
	dp[0][0] = 1;
	for(int i = 0; i < n; i++) for(int msk = 0; msk < 1<<n; msk++) if(i == count(msk)){
		for(int j = 0; j < n; j++) if(!(msk & (1 << j)) && a[i][j]) {
			dp[i+1][msk | (1 << j)] += dp[i][msk];
			dp[i+1][msk | (1 << j)] %= MOD;
		} 	
	}
	cout << dp[n][(1 << n) - 1] << endl;
}
