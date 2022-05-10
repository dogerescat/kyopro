#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;
void ts(Graph &G, vector<bool> &seen, vector<int> &order, int v) {
	seen[v] = true;
	for(int u : G[v]) {
		if(seen[u]) continue;	
		ts(G, seen, order, u);
	}
	order.push_back(v);
}
int main() {
	int n, m; cin >> n >> m;
	Graph G(n);
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		--x, --y;
		G[x].push_back(y);
	}
	vector<bool> seen(n);	
	vector<int> order;
	for(int i = 0; i < n; i++) {
		if(seen[i]) continue;
		ts(G, seen, order, i);
	}
	reverse(order.begin(), order.end());
	vector<int> dist(n);
	for(int i : order) {
		for(auto j : G[i]) {
			dist[j] = max(dist[j], dist[i] + 1);
		}
	}	
	int ans = 0;
	for(int i = 0; i < n; i++) ans = max(ans, dist[i]);
	cout << ans << endl;
}
