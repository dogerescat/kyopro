#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;
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
	int n, m, k; cin >> n >> m >> k;
	UnionFind uf(n);
	vector<int> deg(n);
	Graph block(n);	
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		--a , --b;
		deg[a]++;
		deg[b]++;
		uf.unite(a, b);
	}
	for(int i = 0; i < k; i ++) {
		int a, b; cin >> a >> b;
		--a, --b;
		block[a].push_back(b);
		block[b].push_back(a);
	}	
	for(int i = 0; i < n; i++) {
		int ans = uf.size(i) - 1 - deg[i];	
		for(int j : block[i]) if(uf.issame(i, j)) --ans;
		printf("%d%c", ans, i == n-1 ? '\n' : ' ');
	}
}
