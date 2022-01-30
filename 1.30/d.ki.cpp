#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

void dfs(Graph &G, vector<int> &ans, int v, int pre = -1) {
	for(auto i : G[v]) {
		if(i == pre) continue;
		ans[i] += ans[v];
		dfs(G, ans, i, v);
	}
}
int main() {
	int n, q; cin >> n >> q;
	Graph G(n);
	for(int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;
		--a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int> ans(n);
	for(int i = 0; i < q; i++) {
		int p, x; cin >> p >> x;
		--p;
		ans[p] += x;
	}
	dfs(G, ans, 0);	
	for(int i = 0; i < n; i++) cout << ans[i] << ' ';
	cout << endl;
}
