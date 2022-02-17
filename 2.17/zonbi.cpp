#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using ll = long long;
using namespace std;
typedef pair<ll, int> P;
template<class T> bool chmin(T &a, T b) {
	if(a > b) {
		a = b; 
		return true;
	}
	return false;
}

struct Edge {
	int to; ll weight;
	Edge(int t, int w) : to(t), weight(w) {}
};

typedef vector<vector<Edge>> Graph;
const ll INF = 1e18;

int main() {
	int n, m, k, s; cin >> n >> m >> k >> s;
	ll p, q; cin >> p >> q;
	vector<bool> domi(n); 
	for(int i = 0; i < k; i++) {
		int c; cin >> c;
		--c;
		domi[c] = true;
	}
	Graph G(n);
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		--a, --b;
		G[a].push_back(Edge(b, 0));
		G[b].push_back(Edge(a, 0));
	}	
	vector<bool> denger(n);
	for(int iter = 0; iter < n; iter++) {
		if(!domi[iter]) continue;
		vector<int> seen(n, -1);
	    queue<int> que;
		seen[iter] = 0;
		que.push(iter);
		while(!que.empty()) {
			int v = que.front(); que.pop();
			if(seen[v] <= s) denger[v] = true;
			for(auto e : G[v]) {
				if(seen[e.to] != -1) continue;
				seen[e.to] = seen[v] + 1;
				que.push(e.to);
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(auto &e : G[i]) {
			if(e.to == n-1) continue;
			if(denger[e.to]) e.weight = q;
			else e.weight = p;
		}
	}
	priority_queue<P, vector<P>, greater<P>> heap;
	vector<ll> dist(n, INF);
	dist[0] = 0LL;
	heap.push(P(dist[0], 0));
	while(!heap.empty()) {
		int v = heap.top().second;
		ll d = heap.top().first;
		heap.pop();
		if(d > dist[v]) continue;
		for(auto e : G[v]) {
			if(domi[e.to]) continue;
			if(chmin(dist[e.to], d + e.weight)) {
				heap.push(P(dist[e.to], e.to));
			}
		}
	}
	cout << dist[n-1] << endl;
}
