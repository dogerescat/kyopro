#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll MOD = 1e9+7;

int main() {
	int n, m; cin >> n >> m;	
	Graph G(n);
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		--a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	queue<int> que;	
	vector<int> dist(n, -1);
	vector<ll> cnt(n);
	cnt[0] = 1;
	dist[0] = 0;
	que.push(0);
	while(!que.empty()) {
		int v = que.front(); que.pop();
		for(int i : G[v]) {
			if(dist[i] != -1 && dist[v] >= dist[i]) continue;
			cnt[i] += cnt[v];
			cnt[i] %= MOD;
			if(dist[i] == -1) {
				dist[i] = dist[v] + 1;
				que.push(i);
			}
		}
	}
	cout << cnt[n-1] << endl;
}
