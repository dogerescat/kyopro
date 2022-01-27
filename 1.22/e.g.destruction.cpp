#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
using ll = long long;
typedef pair<int ,pair<int, int>> P;

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
	vector<P> A(m);
	for(int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		--a, --b;
		A[i] = P(c, make_pair(a, b));
	}	
	sort(A.begin(), A.end());
	UnionFind uf(n);
	ll ans = 0;
	for(int i = 0; i < m; i++) {
		int u = A[i].second.first, v = A[i].second.second;
		ll w = A[i].first;
		if(!uf.issame(u, v) || w < 0) {
			uf.unite(u, v);
			continue;
		}
		ans += w;
	}
	cout << ans << endl;
}
