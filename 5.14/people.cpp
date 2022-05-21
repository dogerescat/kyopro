#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Edge {
	int to, weight;
	Edge(int t, int w) : to(t), weight(w) {}
};

using Graph = vector<vector<Edge>>;
const int INF = 1001001001;
int main() {
	int n, m; cin >> n >> m;
	Graph G(n);	
	for(int i = 0; i < m; i++) {
		int l, r, d; cin >> l >> r >> d;
		--l, --r;
		G[l].push_back(Edge(r, d));
		G[r].push_back(Edge(l, -d));
	}
	vector<int> dist(n, INF);
	queue<int> que;
	for(int i = 0; i < n; i++) {
		if(dist[i] != INF) continue;
		que.push(i);
		dist[i] = 0;
		while(!que.empty()) {
			int v = que.front(); que.pop();
			for(auto e : G[v]) {
				if(dist[e.to] != INF) {
					if(dist[v] + e.weight != dist[e.to]) {
						cout << "No" << endl;
						return 0;
					} else continue;
				}
				dist[e.to] = dist[v] + e.weight;
				que.push(e.to);
			}
		}
	}
	cout << "Yes" << endl;
}
