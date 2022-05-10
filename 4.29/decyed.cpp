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
	ll size(int i) {
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
	ll n, m; cin >> n >> m;
	vector<ll> a(m), b(m);
	for(int i = 0; i < m; i++) cin >> a[i] >> b[i];
	for(int i = 0; i < m; i++) {
		--a[i], --b[i];
	}
	UnionFind uf(n);		
	ll total = n * (n-1) / 2;
	vector<ll> ans(m);
	for(int i = m-1; i >= 0; i--) {
		ans[i] = total;	
		if(uf.issame(a[i], b[i])) continue;
		total -= uf.size(a[i]) * uf.size(b[i]);
		uf.unite(a[i], b[i]);
	}
	for(int i = 0; i < m; i++) {
		cout << ans[i] << endl;
	}
}
