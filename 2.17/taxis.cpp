#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
const int INF = 1e9;
typedef pair<int, int> P;

struct Edge {
	int to, weight;
	Edge(int t, int w) : to(t), weight(w) {}
};

typedef vector<vector<Edge>> Graph;
template<class T> bool chmin(T &a, T b) {
	if(a > b) {
		a = b;
		return true;
	}
	return false;
}

int main() {
	int n, k; cin >> n >> k;
	vector<int> c(n), r(n);
	for(int i = 0; i < n; i++) cin >> c[i] >> r[i];
	Graph G(n);
	for(int i = 0; i < k; i++) {
		int a, b; cin >> a >> b;
		--a, --b;
		G[a].push_back(Edge(b, c[a]));
		G[b].push_back(Edge(a, c[b]));
	}
	vector<vector<int>> seen(n, vector<int> (n, -1));	
	for(int i = 0; i < n; i++) {
		queue<int> que;	
		seen[i][i] = 0;
		que.push(i);
		while(!que.empty()) {
			int v = que.front(); que.pop();
			for(auto e : G[v]) {
				if(seen[i][e.to] != -1) continue;
				seen[i][e.to] = seen[i][v] + 1;
				que.push(e.to);
			}
		}
	}
	Graph g(n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(seen[i][j] > r[i]) continue;
			g[i].push_back(Edge(j, c[i]));
		}
	}
	vector<int> dist(n, INF);
	priority_queue<P, vector<P>, greater<P>> heap;			
	dist[0] = 0;
	heap.push(P(dist[0], 0));
	while(!heap.empty()) {
		int v = heap.top().second;
		int d = heap.top().first;
		heap.pop();
		if(d > dist[v]) continue;
		for(auto e : g[v]) {
			if(chmin(dist[e.to], d + e.weight)) {
				heap.push(P(dist[e.to], e.to));
			}				
		}
	}
	cout << dist[n-1] << endl;
}
