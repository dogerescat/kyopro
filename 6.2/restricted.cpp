#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
	int n, m; cin >> n >> m;
	Graph G(n);
	vector<int> indeg(n);
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		--a, --b;
		G[a].push_back(b);
		indeg[b]++;
	}
	priority_queue<int, vector<int>, greater<int>> heap;
	vector<int> ans;
	for(int i = 0; i < n; i++) if(!indeg[i]) heap.push(i);
	while(!heap.empty()) {
		int v = heap.top(); heap.pop();
		ans.push_back(v+1);
		for(int u : G[v]) {
			indeg[u]--;
			if(!indeg[u]) heap.push(u);
		}
	}
	for(int i = 0; i < n; i++) if(indeg[i]) {
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < n; i++) cout << ans[i] << ' ';
	cout << endl;
}
