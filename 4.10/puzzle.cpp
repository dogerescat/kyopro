#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
	int m; cin >> m;	
	Graph G(9);
	for(int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		--u, --v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	string s = "999999999";
	for(int i = 1; i <= 8; i++) {
		int p; cin >> p;
		--p;
		s[p] = i + '0';	
	}
	queue<string> que;
	map<string, int> dist;	
	que.push(s);
	dist[s] = 0;
	while(!que.empty()) {
		string s = que.front(); que.pop();
		int v;
		for(int i = 0; i < 9; i++) if(s[i] == '9') v = i;
		for(auto u : G[v]) {
			string t = s;	
			swap(t[u], t[v]);
			if(dist.count(t)) continue;
			dist[t] = dist[s] + 1;
			que.push(t);
		}
	}
	if(dist.count("123456789") == 0) cout << -1 << endl; 
	else cout << dist["123456789"] << endl;
}
