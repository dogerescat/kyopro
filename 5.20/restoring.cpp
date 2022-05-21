#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
template<class T> bool chmin(T &a, T b) {
	if(a >= b) {
		a = b;
		return true;
	}
	return false;
}

int main() {
	int n; cin >> n;
	vector<vector<int>> a(n, vector<int> (n));
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a[i][j];
	vector<vector<int>> dp(n, vector<int> (n));
	vector<vector<bool>> check(n, vector<bool> (n));
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) dp[i][j] = a[i][j];
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(i == k || j == k) continue;
				if(chmin(dp[i][j], dp[i][k] + dp[k][j])) {
					check[i][j] = true;
				}	
			}
		}
	}
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(dp[i][j] != a[i][j]) {
		cout << -1 << endl;	
		return 0;
	}
	ll ans = 0;	
	for(int i = 0; i < n; i++) for(int j = 0; j < i; j++) {
		if(check[i][j]) continue;
		ans += dp[i][j];
	}
	cout << ans << endl;
}
