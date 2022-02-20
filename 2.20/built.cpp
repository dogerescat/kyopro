#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
typedef pair<int, P> PP;
typedef vector<PP> Edge;
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
	Edge E;
	vector<pair<int, int>> X(n);
	vector<pair<int, int>> Y(n);
	for(int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		X[i].first = x;
		X[i].second = i;
		Y[i].first = y;
		Y[i].second = i;
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	for(int i = 1; i < n; i++) {
		E.push_back(PP(abs(X[i].first - X[i-1].first), P(X[i].second, X[i-1].second)));
		E.push_back(PP(abs(Y[i].first - Y[i-1].first), P(Y[i].second, Y[i-1].second)));
	}	
	sort(E.begin(), E.end());
	UnionFind uf(n);
	ll ans = 0;	
	for(auto e : E) {
		int w = e.first;	
		int u = e.second.first;
		int v = e.second.second;
		if(uf.issame(u, v)) continue;
		ans += w;
		uf.unite(u, v);
	}
	cout << ans << endl;
}
