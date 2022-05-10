#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
typedef pair<ll, ll> P;

int main() {
	ll n, m, k, s, t, x; cin >> n >> m >> k >> s >> t >> x;
	--s, --t, --x;
	vector<P> edge(m);	
	for(auto& p : edge) {
		cin >> p.first >> p.second;	
		--p.first, --p.second;
	}
	vector<vector<vector<ll>>> dp(k+1, vector<vector<ll>>(n, vector<ll>(2)));	
	dp[0][s][0] = 1;
	for(int i = 0; i < k; i++) {
		for(auto p : edge) {
			ll u = p.first, v = p.second;
			for(int j = 0; j < 2; j++) {
				dp[i+1][v][j ^ (v==x)] += dp[i][u][j];
				dp[i+1][v][j ^ (v==x)] %= MOD;
				dp[i+1][u][j ^ (u==x)] += dp[i][v][j];
				dp[i+1][u][j ^ (u==x)] %= MOD;
			}
		}
	}
	cout << dp[k][t][0] << endl;
}
