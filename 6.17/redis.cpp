#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main() {
	int s; cin >> s;	
	vector<ll> dp(s+1);
	dp[0] = 1;
	ll x = 0;
	for(int i = 1; i <= s; i++) {
		if(i - 3 >= 0) {
			x += dp[i-3];
			x %= MOD;
		}
		dp[i] = x;
	}
	cout << dp[s] << endl;
}
