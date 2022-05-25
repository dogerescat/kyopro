#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
	int n; cin >> n;
	Graph G(n);	
	for(int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;
		--a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	queue<int> que;
	vector<int> dist(n, -1);
	dist[0] = 0;
	que.push(0);
	while(!que.empty()) {
		int v = que.front(); que.pop();
		for(int u : G[v]) {
			if(dist[u] != -1) continue;
			dist[u] = dist[v] + 1;
			que.push(u);
		}
	}
	vector<int> dist2(n, -1);
	dist2[n-1] = 0;
	que.push(n-1);
	while(!que.empty()) {
		int v = que.front(); que.pop();
		for(int u : G[v]) {
			if(dist2[u] != -1) continue;
			dist2[u] = dist2[v] + 1;
			que.push(u);	
		}
	}
	int fn = 0; 
	int sn = 0;
	auto df = [&](int i) {
		if(dist[i] - dist[0] <= dist2[i] - dist2[n-1]) return true;	
		else return false;
	};
	for(int i = 1; i < n-1; i++) {
		if(df(i)) fn++;
		else sn++;
	}
	if(fn > sn) cout << "Fennec" << endl;
	else cout << "Snuke" << endl;
}
