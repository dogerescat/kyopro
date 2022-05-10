#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int>>;

void dfs(Graph &G, vector<int> &c, vector<int> &cnt, vector<int> &ans, int v, int pre=-1) {
	if(cnt[c[v]] == 0) ans.push_back(v+1);
	cnt[c[v]]++;
	for(auto u : G[v]) {
		if(u == pre) continue;
		dfs(G, c, cnt, ans, u, v);
	}
	cnt[c[v]]--;
}

int main() {
	int n; cin >> n;
	vector<int> c(n);
	for(int i = 0; i < n; i++) cin >> c[i];
	Graph G(n);	
	for(int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;
		--a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int> cnt(100001);
	vector<int> ans;
	dfs(G, c, cnt, ans, 0);
	sort(ans.begin(), ans.end());
	for(auto i : ans) {
		cout << i << endl;
	}
}
