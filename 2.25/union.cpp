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
	int n, q; cin >> n >> q;
	UnionFind uf(n);
	for(int i = 0; i < q; i++) {
		int com, x, y; cin >> com >> x >> y;
		if(com) {
			if(uf.issame(x, y)) cout << 1 << endl;
			else cout << 0 << endl;
		} else {
			uf.unite(x, y);
		}
	}
}
