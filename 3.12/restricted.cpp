#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
	int n, m; cin >> n >> m;
	Graph G(n);	
	vector<int> indegree(n);
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		--a, --b;
		G[a].push_back(b);
		indegree[b]++;
	}
	priority_queue<int, vector<int>, greater<int>> heap;	
	for(int i = 0; i < n; i++) if(!indegree[i]) heap.push(i);
	vector<int> ans;
	while(!heap.empty()) {
		int v = heap.top(); heap.pop();
		ans.push_back(v+1);	
		for(auto u : G[v]) {
			indegree[u]--;	
			if(!indegree[u]) heap.push(u);
		}
	}
	if(ans.size() != n) {
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
	cout << endl;
}
