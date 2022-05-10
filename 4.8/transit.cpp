#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
struct Edge {
	int to; ll weight;
	Edge(int t, ll w) : to(t), weight(w) {}	
};
using Graph = vector<vector<Edge>>;
void dfs(Graph &G, vector<ll> &dist, int v, ll d) {
	for(auto e : G[v]) {
		if(dist[e.to] != -1) continue;
		dist[e.to] = dist[v] + e.weight;
		dfs(G, dist, e.to, dist[e.to]);
	}
}
int main() {
	int n, q, k; cin >> n;
	Graph G(n);
	for(int i = 0; i < n-1; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		--a, --b;
		G[a].push_back(Edge(b, w));
		G[b].push_back(Edge(a, w));
	}	
	cin >> q >> k;
	--k;
	vector<ll> dist(n, -1);
	dist[k] = 0;
	dfs(G, dist, k, 0);
	for(int i = 0; i < q; i++) {
		int x, y; cin >> x >> y;
		--x, --y;
		ll ans = dist[x] + dist[y];
		cout << ans << endl;
	}	
}
