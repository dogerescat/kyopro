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
	vector<int> a(m), b(m);
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		--x, --y;
		a[i] = x, b[i] = y;
	}
	int ans = 0;
	for(int i = 0; i < m; i++) {
		UnionFind uf(n);
		bool ok = true;
		for(int j = 0; j < m; j++) {
			if(i == j) continue;
			uf.unite(a[j], b[j]);
		}
		for(int j  = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				if(!uf.issame(j, k)) ok = false;
			}	
		}	
		if(!ok) ans++;
	}
	cout << ans << endl;
}
