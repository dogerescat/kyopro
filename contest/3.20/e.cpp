#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;
const int MOD = 998244353;

int main() {
	int n, m, k, s, t, x; cin >> n >> m >> k >> s >> t >> x;	
	--s, --t, --x;
	Graph G(n);
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		--a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int> dist(n, -1);	
	queue<int> que;
	dist[s] = 0;
	que.push(s);
	while(!que.empty()) {
		int v = que.front(); que.pop();
		for(auto u : G[v]) {
			if(dist[u] != -1) continue;
			dist[u] = dist[v] + 1;
			que.push(u);
		}
	}
	if(dist[t] == -1 || dist[t] > k) {
		cout << 0 << endl;
		return 0;
	}
	
}
