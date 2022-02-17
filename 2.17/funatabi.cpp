#include <iostream>
#include <vector>
using namespace std;

template<class T> bool chmin(T &a, T b) {
	if(a > b) {
		a = b;
		return true;
	}
	return false;
}

struct Edge {
	int to, weight;
	Edge(int t, int w) : to(t), weight(w) {}
};
typedef vector<vector<Edge>> Graph;
const int INF = 1e9;
int main() {
	int n, k; cin >> n >> k;
	Graph G(n);	
	for(int i = 0; i < k; i++) {
		int t; cin >> t;		
		int a, b, c;
		if(t) {
			cin >> a >> b >> c;	
			--a, --b;
			G[a].push_back(Edge(b, c));
			G[b].push_back(Edge(a, c));
		} else {
			cin >> a >> b;
			--a, --b;
			vector<bool> used(n);
			vector<int> dist(n, INF);
			dist[a] = 0;
			for(int iter = 0; iter < n; iter++) {
				int min_dist = INF;
				int min_v = -1;
				for(int v = 0; v < n; v++) {
					if(!used[v] && min_dist > dist[v]) {
						min_dist = dist[v];
						min_v = v;
					}	
				}
				if(min_v == -1) continue;
				for(auto e : G[min_v]) {
					chmin(dist[e.to], min_dist + e.weight);
				}
				used[min_v] = true;
			}
			if(dist[b] == INF) cout << -1 << endl;
			else cout << dist[b] << endl;
		}
	}
}
