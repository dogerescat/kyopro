#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int INF = 1e9;

int f(vi &dp, vvi &sum, vi &c, int m, int S) {
	if(!S) return 0;	
	if(dp[S] != -1) return dp[S];
	int cnt = 0;
	for(int i = 0; i < m; i++) {
		if(S & (1 << i)) cnt += c[i];
	}
	int res = INF;	
	for(int i = 0; i < m; i++) {
		if(!(S & (1 << i)))	continue;
		int t = (c[i] - sum[i][cnt] + sum[i][cnt-c[i]]);
		int rec = f(dp, sum, c, m, S^(1<<i)) + t;
		res = min(res, rec);
	}
	return dp[S] = res;
}

int main() {
	int n, m; cin >> n >> m;
	vi a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vi c(m);
	for(int i = 0; i < n; i++) {
		c[a[i]-1]++;
	}
	vvi sum(m, vi(n+1));	
	for(int i = 0; i < m; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == a[j-1]-1) sum[i][j] = sum[i][j-1] + 1; 
			else sum[i][j] = sum[i][j-1];
		}
	}
	vi dp(1 << m, -1);
	int ans = f(dp, sum, c, m, (1 << m) - 1);
	cout << ans << endl;
}
