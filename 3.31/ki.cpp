#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
	int n, q; cin >> n >> q;
	Graph G(n);
	for(int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;	
		--a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int> count(n);
	for(int i = 0; i < q; i++) {
		int p, x; cin >> p >> x;
		--p;
		count[p] += x;
	}
	queue<int> que;	
	vector<bool> seen(n);
	que.push(0);
	seen[0] = true;
	while(!que.empty()) {
		int v = que.front(); que.pop();
		for(auto u : G[v]) {
			if(seen[u]) continue;	
			count[u] += count[v];
			seen[v] = true;
			que.push(u);
		}
	}
	for(int i = 0; i < n; i++) cout << count[i] << " ";
	cout << endl;
}
