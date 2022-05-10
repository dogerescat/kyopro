#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
using Graph = vector<vector<int>>;
struct Q {
	int i, k;
	Q(int i, int k) : i(i), k(k) {}
};
int main() {
	int n, q; cin >> n >> q;
	vector<int> x(n);
	for(int i = 0; i < n; i++) cin >> x[i];
	Graph G(n);
	for(int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;
		--a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<vector<Q>> qs(n);
	for(int i = 0; i < q; i++) {
		int v, k; cin >> v >> k;
		--v, --k;
		qs[v].emplace_back(Q(i, k));
	}
	vector<int> ans(q);
	const int K = 20;
	auto merge = [&](vector<int> &a, const vector<int> b) {
		a.insert(a.begin(), b.begin(), b.end());
		sort(a.rbegin(), a.rend());
		a.resize(K);
	
	};
	auto dfs = [&](auto f, int v, int p = -1) -> vector<int> {
		vector<int> res(K);		
		res[0] = x[v];
		for(auto u : G[v]) {
			if(u == p) continue;
			auto d = f(f, u, v);
			merge(res, d);
		}
		for(auto [i, k] : qs[v]) {
			ans[i] = res[k];	
		}
		return res;
	};	
	dfs(dfs, 0);
	for(int i = 0; i < q; i++) {
		printf("%d\n", ans[i]);
	}	
}
