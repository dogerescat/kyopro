#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

int main() {
	int n, k; cin >> n >> k;
	vector<ll> dp(n+1);	
	vector<ll> sum(n+1);
	vector<ll> r(k), l(k);
	for(int i = 0; i < k; i++) cin >> l[i] >> r[i];
	dp[1] = sum[1] = 1;
	for(int i = 2; i <= n; i++) {
		for(int j = 0; j < k; j++) {
			int li = i - r[j];
			int ri = i - l[j];
			li = max(li, 1);
			if(ri < 0) continue; 
			dp[i] = (dp[i] + (sum[ri] - sum[li-1] + MOD) % MOD) % MOD;
		}
		sum[i] = (sum[i-1] + dp[i]) % MOD;
	}
	cout << dp[n] << endl;
}
