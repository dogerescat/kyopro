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
	Graph G(n);	
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;	
		--a, --b;
		G[a].push_back(b);
	}
	vector<int> ans(n);
	int cnt = 0;
	UnionFind uf(n);
	for(int i = n-1; i >= 0; i--) {
		ans[i] = cnt;	
		cnt++;
		for(auto v : G[i]) {
			if(!uf.issame(i, v)) {
				cnt--;	
				uf.unite(i, v);
			}
		}
	}
	for(int i = 0; i < n; i++) cout << ans[i] << endl;
}
