#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

void dfs(Graph &G, vector<int> &order, int v, int pre = -1) {
	order.push_back(v);
	for(int u : G[v]) {
		if(pre == u) continue;
		dfs(G, order, u, v);
		order.push_back(v);
	}
}
int main() {
	int n; cin >> n;
	Graph G(n);
	for(int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;
		--a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i = 0; i < n; i++) sort(G[i].begin(), G[i].end());
	vector<int> order;
	dfs(G, order, 0);
	for(int i : order) cout << i + 1 << ' ';
	cout << endl;
}
