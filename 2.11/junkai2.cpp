#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
const int INF = 1e9;
int f(vvi &dp, vvi &dist, int n, int bit, int v) {
	if(dp[bit][v] != -1) return dp[bit][v];
	if(bit == (1 << n) - 1 && v == 0) return dp[bit][v] = 0;
	int res = INF;
	for(int i = 0; i < n; i++) {
		if(dist[v][i] != -1 && !(bit & (1 << i))) {
			res = min(res, f(dp, dist, n, bit | (1 << i), i)+dist[v][i]);
		}
	}
	return dp[bit][v] = res;
}
int main() {
	int n, m; cin >> n >> m;
	vvi dist(n, vi(n, -1));
	for(int i = 0; i < m; i++) {
		int a, b, d; cin >> a >> b >> d;
		dist[a][b] = d;
	}
	vvi dp((1 << n)+1, vi(n, -1));
	int ans = f(dp, dist, n, 0, 0);	
	if(ans == INF) cout << -1 << endl;
	else cout << ans << endl;
}
