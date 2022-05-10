#include <iostream>
#include <vector> 
#include <utility>
#include <algorithm>
using namespace std;
using ll = long long;
typedef pair<int, int> P;

struct UnionFind {
	vector<int> par, siz;
    UnionFind(int n): par(n, -1), siz(n, 1) {}

    int root(int i) {
        if(par[i] == -1) return i;
        else return par[i] = root(par[i]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
     	x = root(x); y = root(y);
        if(x == y) return false;
        if(siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }
};

int main() {
	int n; cin >> n;
	vector<pair<int, P>> edge(n-1);
	for(int i = 0; i < n-1; i++) {
		int u, v, w; cin >> u >> v >> w;
		--u, --v;
		edge[i].first = w;	
		edge[i].second.first = u;
		edge[i].second.second = v;
	}
	sort(edge.begin(), edge.end());
	UnionFind uf(n);	
	ll ans = 0;
	for(auto [w, p] : edge) {
		auto [u, v] = p;
		ans += (ll) w * uf.siz[uf.root(u)] * uf.siz[uf.root(v)];
		uf.unite(u, v); 
	}
	cout << ans << endl;
}
