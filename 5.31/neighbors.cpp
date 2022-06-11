#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

bool dfs(Graph &G, vector<bool> &a, int v, int pre = -1) {
	if(a[v]) return false;
	else a[v] = true;
	bool ok = true;
	for(int u : G[v]) {
		if(u == pre) continue;
		ok = dfs(G, a, u, v);
	}	
	return ok;
}
int main() {
	int n, m; cin >> n >> m;
	Graph G(n);
	vector<int> cnt(n);
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		--a, --b;
		cnt[a]++; cnt[b]++;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i = 0; i < n; i++) if(cnt[i] >= 3) {
		cout << "No" << endl;
		return 0;
	}
	vector<bool> a(n);
	bool ok = true;
	for(int i = 0; i < n; i++) {
		if(a[i]) continue;
		if(!dfs(G, a, i)) ok = false;
	}	
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
}
