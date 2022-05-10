#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;
	vector<vector<int>> to(n);	
	for(int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;
		--a, --b;
		to[a].push_back(b);	
		to[b].push_back(a);
	}
	vector<int> l(n), r(n);
	int x = 1;
	auto dfs = [&](auto f, int v, int p = -1) -> void {
		l[v] = x;	
		for(auto u : to[v]) {
			if(u == p) continue;
			f(f, u, v);
		}
		if(to[v].size() == 1 && p != -1) {
			x++;
		}
		r[v] = x-1;
	};
	dfs(dfs, 0);
	for(int i = 0; i < n; i++) {
		printf("%d %d\n", l[i], r[i]);
	}
}
