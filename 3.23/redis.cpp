#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main() {
	ll s; cin >> s;	
	vector<ll> dp(s+1);
	dp[0] = 1;
	for(int i = 1; i <= s; i++) {
		for(int j = 0; j < i-2; j++) {
			dp[i] += dp[j];	
			dp[i] %= MOD;
		}	
	}
	cout << dp[s] << endl;
}
