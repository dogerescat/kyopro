#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
using ll = long long;
struct Edge {
	int to, weight;
	Edge(int t, int w) : to(t), weight(w) {}	
};
template<class T> bool chmin(T &a, T b) {
	if(a > b) {
		a = b;
		return true;
	}
	return false;
}
typedef vector<vector<Edge>> Graph;
const int INF = 1e9;
int main() {
	int n, m, r; cin >> n >> m >> r;
	Graph G(n);
	for(int i = 0; i < m; i++) {
		int s, t, d; cin >> s >> t >> d;
		G[s].push_back(Edge(t, d));
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> heap;
	vector<int> dist(n, INF);
	dist[r] = 0;
	heap.push(make_pair(dist[r], r));
	while(!heap.empty()) {
		int v = heap.top().second;
		int d = heap.top().first;
		heap.pop();
		if(d > dist[v]) continue;
		for(auto e : G[v]) {
			if(chmin(dist[e.to], dist[v] + e.weight)) {
				heap.push(make_pair(dist[e.to], e.to));
			}
		}
	}
	for(int i = 0; i < n; i++) {
		if(dist[i] == INF) cout << "INF" << endl;
		else cout << dist[i] << endl;
	}
}
