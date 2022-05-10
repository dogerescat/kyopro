#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
struct UnionFind {
	vector<ll> par, siz;
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
	vector<ll> a(m), b(m);
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		--x, --y;
		a[i] = x;
		b[i] = y;
	}
	UnionFind uf(n);	
	vector<ll> ans(m);
	ans[m-1] = 1LL * n * (n-1)/2;
	for(int i = m-2; i >= 0; i--) {
		if(uf.issame(a[i+1], b[i+1])) ans[i] = ans[i+1];
		else {
			ans[i] = ans[i+1] - (uf.siz[uf.root(a[i+1])] * uf.siz[uf.root(b[i+1])]);
		}
		uf.unite(a[i+1], b[i+1]);
	}
	for(auto i : ans) cout << i << endl;
}
