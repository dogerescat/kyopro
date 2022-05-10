#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
	int to, weight;	
	Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;

int main() {
	int n; cin >> n;
	Graph G(n);
	for(int i = 0; i < n-1; i++) {
		int a, b, c; cin >> a >> b >> c;
		--a, --b;
		G[a].push_back(Edge(b, c));
		G[b].push_back(Edge(a, c));
	}
	vector<int> ans(n, -1);
	queue<int> que;
	ans[0] = 0;
	que.push(0);
	while(!que.empty()) {
		int v = que.front(); que.pop();
		for(auto e : G[v]) {
			if(ans[e.to] != -1) continue;
			ans[e.to] = (ans[v] + e.weight) % 2;
			que.push(e.to);
		}
	}
	for(int i = 0; i < n; i++) cout << ans[i] << ' ';
	cout << endl;
}
