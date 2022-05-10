#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;
const int INF = 1001001001;

int main() {
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	Graph G(n);	
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		--x, --y;
		G[x].push_back(y);
	}
	int ans = -INF;	
	vector<int> dp(n, INF*2);
	for(int i = 0; i < n; i++) {
		ans = max(ans, a[i] - dp[i]);
		for(auto j : G[i]) {
			dp[j] = min(dp[j], dp[i]);
			dp[j] = min(dp[j], a[i]);
		}
	}
	cout << ans << endl;
}
