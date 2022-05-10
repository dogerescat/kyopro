#include <iostream>
#include <vector>
using namespace std;

struct Edge {
	int to, id;
	Edge(int t, int i) : to(t), id(i) {}
};

using Graph = vector<vector<Edge>>;
vector<int> ans;

void dfs(Graph &G, int v, int c=-1, int p=-1) {
	int k = 1;
	for(auto e : G[v]) {
		if(p == e.to) continue;
		if(k == c) k++;
		ans[e.id] = k; k++;
		dfs(G, e.to, ans[e.id], v);
	}
}

int main() {
	int n; cin >> n;
	ans.resize(n);
	Graph G(n);	
	vector<int> dg(n);
	for(int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;
		--a, --b;
		dg[a]++;
		dg[b]++;
		G[a].push_back(Edge(b, i));
		G[b].push_back(Edge(a, i));
	}
	dfs(G, 0);	
	int k = 0;
	for(int i = 0; i < n-1; i++) k = max(k, dg[i]);
	cout << k << endl;
	for(int i = 0; i < n-1; i++) {
		cout << ans[i] << endl;
	}
}
