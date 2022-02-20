#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef vector<pair<int, pair<int, int>>> Edge;
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
	int n, m; cin >> n >> m;
	Edge e(m);
	for(int i = 0; i < m; i++) {
		int a, b, w; cin >> a >> b >> w;
		e[i].first = w;
		e[i].second.first = a;
		e[i].second.second = b;
	}
	sort(e.begin(), e.end());
	UnionFind uf(n);
	int ans = 0;
	for(int i = 0; i < m; i++) {
		int w = e[i].first;
		int u = e[i].second.first;
		int v = e[i].second.second;
		if(uf.issame(u, v)) continue;
		ans += w;
		uf.unite(u, v);
	}
	cout << ans << endl;
}
