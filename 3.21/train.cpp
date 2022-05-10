#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
const ll INF = 1001001001001001;
template<class T> bool chmin(T& a, T b) {
	if(a > b) {
		a = b;
		return true;
	}
	return false;
}

struct Edge {
	int to, k; ll w;
	Edge(int t, int k, int w) : to(t),k(k), w(w) {}
};

int main() {
	int n, m, x, y; cin >> n >> m >> x >> y;	
	--x, --y;
	vector<vector<Edge>> G(n);
	for(int i = 0; i < m; i++) {
		int a, b, t, k; cin >> a >> b >> t >> k;
		--a, --b;	
		G[a].push_back(Edge(b, k, t));	
		G[b].push_back(Edge(a, k, t));
	}
	vector<ll> dist(n, INF);
	dist[x] = 0;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>heap;	
	heap.push(make_pair(dist[x], x));
	while(!heap.empty()) {
		int v = heap.top().second;
		ll d = heap.top().first;
		heap.pop();
		if(d > dist[v]) continue;
		for(auto e: G[v]) {
			int a = 0;
			if(dist[v] % e.k != 0) {
				a = e.k - (dist[v] % e.k);
			} 
			if(chmin(dist[e.to], dist[v] + e.w + a)) {
				heap.push(make_pair(dist[e.to], e.to));
			}
		}
	}
	if(dist[y] == INF) cout << -1 << endl;
	else cout << dist[y] << endl;
}
