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
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	int m = 0;
	for(int i = 0; i < n; i++) m = max(m, a[i]);
	UnionFind uf(m+1);
	int ans = 0;
	for(int i = 0; i < n / 2; i++) {
		if(!uf.issame(a[i], a[n-i-1])) {
			ans++;
			uf.unite(a[i], a[n-i-1]);
		}
	}
	cout << ans << endl;
}
