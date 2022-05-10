#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
	int n, m; cin >> n >> m;
	Graph G(n);
	vector<int> deg(n);
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		--a, --b;
		G[a].push_back(b);	
		deg[b]++;
	}
	priority_queue<int, vector<int>, greater<int>> heap;
	for(int i = 0; i < n; i++) if(!deg[i]) heap.push(i);
	vector<int> ans;
	while(!heap.empty()) {
		int v = heap.top(); heap.pop();
		for(auto u : G[v]) {
			deg[u]--;
			if(!deg[u]) heap.push(u);
		}
		ans.push_back(v+1);
	}
	if(ans.size() != n) {
		cout << -1 << endl;
		return 0;
	} 
	for(int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}
