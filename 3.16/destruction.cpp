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
	int n, m; cin >> n >> m;
	vector<int> a(m), b(m);
	vector<P> c(m);
	for(int i = 0; i < m; i++) {
		cin >> a[i] >> b[i] >> c[i].first;
		--a[i], --b[i];
		c[i].second = i;
	}
	sort(c.begin(), c.end());
	UnionFind uf(n);
	ll ans = 0;	
	for(int i = 0; i < m; i++) {
		int index = c[i].second;
		if(c[i].first <= 0) {
			uf.unite(a[index], b[index]);
			continue;
		}  
		if(uf.issame(a[index], b[index])) {
			ans += c[i].first;	
		} else {
			uf.unite(a[index], b[index]);
		}
	}
	cout << ans << endl;
}
