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
	int n; cin >> n;
	vector<int> a(n);
	int M = 200005;
	for(int i = 0; i < n; i++) cin >> a[i];
	UnionFind uf(M);
	for(int i = 0; i < n; i++) uf.unite(a[i], a[n-i-1]);
	int ans = 0;
	for(int i = 0; i < M; i++) {
		if(i != uf.root(i)) continue;	
		ans += uf.siz[i]-1;		
	}	
	cout << ans << endl;
}
