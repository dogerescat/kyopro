#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

int main() {
	ll n; cin >> n;
	vector<vector<ll>> a(n+2, vector<ll>(11, 0));	
	for(int i = 1; i <= 9; i++) {
		a[1][i] = 1;
	}
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j <= 9; j++) {
			a[i][j] = (a[i][j] + a[i-1][j] + a[i-1][j-1] + a[i-1][j+1]) % MOD;	
		}
	}
	ll ans = 0;
	for(int i = 1; i <= 9; i++) {
		ans = (ans + a[n][i]) % MOD;
	}
	cout << ans << endl;
}
