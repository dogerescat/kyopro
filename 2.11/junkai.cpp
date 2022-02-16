#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
struct Edge {
	int to, weight;
	Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
const int INF = 1e9;

int f(vvi &dp, vvi &dist, int &V, int bit, int v) {
	if(dp[bit][v] != -1) return dp[bit][v];	
	if(bit == (1 << v)) return dp[bit][v] = 0;
	int res = INF;
	int prev_bit = bit & ~(1 << v);
	for(int u = 0; u < V; u++) {
		if(!(prev_bit & (1 << u))) continue;
		if(dist[u][v] != -1) res = min(res, f(dp, dist, V, prev_bit, u) + dist[u][v]);
	}	
	return dp[bit][v] = res;
}
int main() {
	int V, E; cin >> V >> E;
	vvi dist(V, vi(V, -1));
	for(int i = 0; i < E; i++) {
		int a, b, d; cin >> a >> b >> d;
		dist[a][b] = d;
	}
	vvi dp((1 << V)+1, vi(V, -1));
	int ans = INF;
	for(int i = 0; i < V; i++) {
		int res = f(dp, dist, V, (1 << V)-1, i);
		for(int j = 0; j < V; j++) {
			if(i != j && dp[(1<<V)-1][j] != -1 && dist[j][i] != -1) res = min(res, dp[(1<<V)-1][j] + dist[j][i]);		
		}
		ans = min(ans, res);	
	}	
	if(ans == INF) cout << -1 << endl;
	else cout << ans << endl;
}
