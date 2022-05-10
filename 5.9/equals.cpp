#include <iostream>
#include <vector>
using namespace std;
struct UnionFind {
	vector<int> par, siz;
    UnionFind(int n): par(n, -1), siz(n, 1) {}

    int root(int i) {
        if(par[i] == -1) return i;
        else return par[i] = root(par[i]);
    }
	int size(int i) {
		return siz[root(i)];
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
	vector<int> p(n);
	for(int i = 0; i < n; i++) cin >> p[i];
	for(int i = 0; i < n; i++) --p[i];
	vector<int> x(m), y(m);
	for(int i = 0; i < m; i++) cin >> x[i] >> y[i];
	for(int i = 0; i < m; i++) --x[i], --y[i];
	UnionFind uf(n);
	for(int i = 0; i < m; i++) {
		uf.unite(x[i], y[i]);
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(p[i] == i) {
			ans++;
		} else {
			if(uf.issame(i, p[i])) ans++;
		}
	}
	cout << ans << endl;
}
